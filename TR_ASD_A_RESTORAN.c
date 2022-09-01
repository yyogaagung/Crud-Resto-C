#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <time.h>
#define MAKS 25

void SetColor(unsigned short);

/*STRUCT MENU RESTORAN*/
struct MenuRestoran{
    int id;
    char namaMenu[MAKS];
    float harga;
    int stok;
    char jenisMenu[MAKS];
}cek, hapus, sort[100], temp;
 struct MenuRestoran info;


/*ROOT*/
char userRoot[]="admin";
char pwRoot[]="admin";
void readPass(char *temp);

/*VARIABEL GLOBAL FITUR LOGIN*/
char username[MAKS], password[MAKS], ch;
int validasiSukses;

/*FUNGSI gotoxy*/
COORD coord = { 0, 0 };
void gotoxy(int x, int y);
/*FUNGSI VALIDASI LOGIN*/
int validasiLogin(char x[MAKS], char y[MAKS]);
/*FUNGSI LOGIN*/
void login();
/*FUNGSI CEK APAKAH FILE SUDAH ADA ATAU BELUM*/
void adaDatabase();
/*FUNGSI MEMILIH MENU*/
int pilihMenu();
/*FUNGSI TAMBAH/CREATE INSTANCE*/
//void create();
void tambahData();
/*FUNGSI TAMPILKAN DATA*/
void display();
/*FUNGSI header pada file*/
void headerDB();
void editData();
void hapusData();
void urutData();
void tampilRiwayat();
void cariData();


int main()
{


    relogin:
    login();
    if(validasiSukses == 1){
        system("cls");
        gotoxy(48, 26);
        printf("Menghubungkan Database");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
        adaDatabase();
        system("cls");
        system("Color F0");
        gotoxy(50, 14);
            Sleep(100);printf("W");
            Sleep(100);printf("e");
            Sleep(100);printf("l");
            Sleep(100);printf("c");
            Sleep(100);printf("o");
            Sleep(100);printf("m");
            Sleep(100);printf("e");
            Sleep(100);printf(" A");
            Sleep(100);printf("d");
            Sleep(100);printf("m");
            Sleep(100);printf("i");
            Sleep(100);printf("n");
            Sleep(100);printf(" :D");
            getch();
        //printf("Welcome Admin :D");getch();
        char choice;
        while(choice != 8){
            system("cls");
            gotoxy(17, 3);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DATABASE RUMAH MAKAN SIANG MALAM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

            gotoxy(17, 18);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

            gotoxy(22, 5);
            printf("1. Tambah Data Menu \n\n");

            gotoxy(22, 6);
            printf("2. Lihat Data Menu\n\n");

            gotoxy(22, 7);
            printf("3. Hapus Data Menu\n\n");

            gotoxy(22, 8);
            printf("4. Update Data Menut\n\n");

            gotoxy(22, 9);
            printf("5. Cari Data Menu\n\n");

            gotoxy(22, 10);
            printf("6. Urutkan Data Menu\n\n");

             gotoxy(22, 11);
            printf("7. Riwayat Aktivitas\n\n");

             gotoxy(22, 12);
            printf("8. Keluar\n\n");

            gotoxy(22, 16);
            printf("Pilih Menu : ");
            scanf(" %c", &choice);

            switch(choice){
                case '1':
                    system("cls");
                    tambahData();
                    system("cls");
                    break;
                case '2':
                    display();
                    break;
                case '3':
                    hapusData();
                    break;
                case '4':
                    editData();
                    break;
                case '5':
                    cariData();
                    break;
                case '6':
                    urutData();
                    break;
                case '7':
                    tampilRiwayat();
                    break;
                case '8':
                    printf("\n\n\n\n");
                    exit(0);
                    break;
                default:
                    gotoxy(22, 17);
                    printf("Inputan tidak ada");
                    getch();

            }

        }


    }else{
        gotoxy(35, 16);
        printf("login gagal, periksa username dan password anda!");
        getch();
        goto relogin;
    }

    return 0;
}

void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*FUNGSI VALIDASI LOGIN*/
int validasiLogin(char x[MAKS], char y[MAKS]){

    int strPersis = strcmp(x, userRoot);
    int strPersis2 = strcmp(y, pwRoot);
    if(strPersis == 0 && strPersis2 == 0){
        return 1;
    }else{
        return 0;
    }

}

/*FUNGSI LOGIN*/
void login(){
//system("Color F0");
system("cls");

    gotoxy(35, 10);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME ADMIN \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(35, 18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(50, 13);
    printf("Username : ");
    scanf("%[^\n]", &username);fflush(stdin);

    gotoxy(50, 14);
    printf("Password : ");
    readPass(password);




validasiSukses = validasiLogin(username, password);


}

/*FUNGSI CEK APAKAH FILE SUDAH ADA ATAU BELUM*/
void adaDatabase(){
    FILE *fptr;
    int  sudahBenar;
    char lagi;
    labelDatabase:
    fptr = fopen("daftar-menu.txt","r");
    if(fptr == NULL){
        system("cls");
        //system("Color F0");
        gotoxy(48, 14);
        printf("Database tidak ditemukan!\n");
        //printf("\nDatabase tidak ada!\n");



        SetColor(7);
        gotoxy(43, 15);
        printf("Apakah ingin buat database ? [Y/T]:");


         do{
            lagi = getchar();
            sudahBenar = (lagi == 'Y') || (lagi == 'y') || (lagi == 'T') || (lagi == 't');
        }while(!sudahBenar);
        if(lagi == 'Y' || lagi == 'y'){
           fopen("daftar-menu.txt","a");
           //headerDB();
            system("cls");
            //system("Color F0");
            gotoxy(47, 15);
            printf("Database berhasil dibuat\n");
            fclose(fptr);
            gotoxy(50, 26);
            printf("Merestart Program");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
            Sleep(500);
            printf(". ");
            exit(1);
        }
        else if(lagi == 'T' || lagi == 't'){
            printf("Database tidak dibuat\n");getch();
            goto labelDatabase;
        }
    }else{
        system("cls");
         gotoxy(48, 14);
        //system("Color F0");
        printf("database terhubung");
        getch();
        fclose(fptr);
    }
}

void readPass(char *temp) {
    int key = 0, index = 0;

    do {
        key = getch(); /* Simpan karakter yang ditekan ke dalam variabel key */

        switch (key) {

                /* 0 adalah kode awal untuk tombol fungsi (function key), seperti F1, F2, ..., F12
                 * Misalkan jika tombol F1 ditekan, maka fungsi getch akan mengembalikan
                 * nilai 0 dan menyimpan sebuah kode yang menandakan tombol F1 ditekan ke buffer.
                 */
            case 0:

                /* 224 adalah kode awal untuk tombol panah, home, page up, page down, end dan lain-lain.
                 * Misalkan jika tombol panah ditekan, fungsi getch akan
                 * mengembalikan nilai 224 dan menyimpan sebuah kode
                 * yang menandakan tombol yang ditekan ke buffer.
                 */
            case 224:

                /* Fungsi getch di sini digunakan untuk membersihkan buffer */
                getch();

                break;

                /* Jika tombol back space ditekan, maka mundurkan cursor satu langkah */
            case '\b':
                if (index > 0) {
                    index = index - 1; /* Kurangi index temp sebesar 1 */
                    temp[index] = 0; /* set temp[index] menjadi kosong (NUL) */

                    printf("\b \b"); /* Mundurkan cursor satu langkah */
                }

                break;
            default:

                /* Hanya karakter printable yang dapat ditekan, seperti huruf, angka dan karakter spesial */
                if (key > 31 && key < 127) {
                    temp[index] = key; /* Simpan karakter ke dalam temp[index] */
                    index = index + 1; /* Naikkan nilai index sebesar 1 */

                    printf("*");
                }
        }

        /* 13 adalah kode ASCII untuk karakter enter.
         * Perulangan akan terus dilakukan sampai tombol enter ditekan.
         */
    } while (key != 13);

    /* Menambahkan NUL di akhir temp yang menandakan akhir dari sebuah string */
    temp[index] = '\0';
}

/*FUNGSI MEMILIH MENU*/

void headerDB(){
    FILE *fptr;
    fptr = fopen("daftar-menu.txt", "a");
    fprintf(fptr, "ID\t NAMA MENU\t\t\t HARGA\t\t\t STOK\t\t JENIS\n");
    fclose(fptr);
}



void tambahData(){
    char lagi;
    FILE *fp, *fpr;
    time_t t;
    time(&t);



    do{
        system("cls");
        gotoxy(17, 3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TAMBAH DATA MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        fp = fopen("daftar-menu.txt", "a");
        fpr = fopen("riwayat.txt", "a");
        gotoxy(17,6);
        printf("Masukan id\t\t: ");fflush(stdin);
        scanf("%d", &info.id);
        gotoxy(17,7);
        printf("Masukan nama menu\t: ");fflush(stdin);
        scanf("%[^\n]", info.namaMenu);
        gotoxy(17,8);
        printf("Masukan harga menu\t: ");
        scanf("%f", &info.harga);
        gotoxy(17,9);
        printf("Masukan stok menu\t: ");
        scanf("%d", &info.stok);
        gotoxy(17,10);
        printf("Masukan jenis menu\t: ");fflush(stdin);
        scanf("%[^\n]", info.jenisMenu);
        fprintf(fpr, "\n%s", ctime(&t));
        fprintf(fpr, "Menambahkan data dengan id %d, nama %s\n", info.id, info.namaMenu);
        fprintf(fp, "%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",info.id, info.namaMenu, info.harga, info.stok, info.jenisMenu);
        gotoxy(30, 25);
        printf("\t\t\tData Berhasil Disimpan");
        fclose(fpr);
        fclose(fp);


        gotoxy(48, 26);
        printf("tambah data lagi? [y/t]");fflush(stdin);

        scanf("%c", &lagi);

    }while(lagi == 'y' || lagi =='Y');



}

void display(){
    system("cls");
    time_t t;
    time(&t);

    FILE *fp, *fpr;
    int test=0;
    fp = fopen("daftar-menu.txt", "r");
    fpr = fopen("riwayat.txt", "a");

    if(fp==NULL){
        fprintf(stderr, "file tidak ditemukan");
    }
    printf("ID\t NAMA MENU\t\t\t HARGA\t\t\t STOK\t\t JENIS\n");
    while(fscanf(fp, "%d %s %f %d %s", &info.id, info.namaMenu, &info.harga, &info.stok, info.jenisMenu)!=EOF){
        printf("%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",info.id, info.namaMenu, info.harga, info.stok, info.jenisMenu);
        test++;
    }
    fprintf(fpr, "\n%s", ctime(&t));
    fprintf(fpr, "Menampilkan data\n");
    fclose(fp);
    fclose(fpr);

    if(test==0){
        gotoxy(52, 14);
        printf ("Data Kosong ! \n");



    }else{
        printf("\n\nJumlah Data : %d", test);
    }


    gotoxy(50, 27);
    Sleep(1000);
    printf("ketik sembarang");


    getch();

}


void hapusData()
{
    time_t t;
    time(&t);
	FILE *lama, *baru, *fpr;
	int test=0;
	lama = fopen("daftar-menu.txt","r");
	baru = fopen("baru.txt","a");
	fpr = fopen("riwayat.txt", "a");
	system("cls");
	gotoxy(17, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 HAPUS DATA MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(17, 5);
	printf("Input No. ID Menu yang akan di hapus : ");fflush(stdin);

	scanf("%d", &hapus.id);fflush(stdin);
	while(fscanf(lama, "%d %s %f %d %s", &info.id, info.namaMenu, &info.harga, &info.stok, info.jenisMenu)!=EOF)
	{
		if(info.id != hapus.id)
		{
			 fprintf(baru, "%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",info.id, info.namaMenu, info.harga, info.stok, info.jenisMenu);
		}
		else{
			test++;
            gotoxy(17, 7);
			printf("Data No ID : %d dengan Nama : %s\n",info.id,info.namaMenu);
			gotoxy(17, 8);
			printf("Berhasil dihapus dari Daftar !");
			fprintf(fpr, "\n%s", ctime(&t));
            fprintf(fpr, "Menghapus data dengan id %d, nama %s\n",info.id, info.namaMenu);
		}
	}

	fclose(lama);
	fclose(baru);
	fclose(fpr);
	remove("daftar-menu.txt");
	rename("baru.txt", "daftar-menu.txt");

		if(test==0){
            gotoxy(17, 7);
            printf("Data tidak ditemukan !\a\a\a");

        }

    gotoxy(52, 27);
    Sleep(1000);
    printf("ketik sembarang");

    getch();
}

void editData(){
    time_t t;
    time(&t);
    int pilih,test=0;
	FILE *lama,*baru, *fpr;
	lama = fopen("daftar-menu.txt","r");
	baru = fopen ("baru.txt","w");
	fpr = fopen("riwayat.txt", "a");
	system("cls");

	printf ("Masukan ID Menu : ");
	scanf ("%d",&cek.id);
	while(fscanf(lama, "%d %s %f %d %s", &info.id, info.namaMenu, &info.harga, &info.stok, info.jenisMenu)!=EOF)
	{
		if(info.id == cek.id)
		{
			test=1;

			ganti:
			    system("cls");
				printf("\nNo. ID : %d dimiliki Menu dengan Nama : %s",info.id,info.namaMenu);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Harga");
				printf("\n[2]. Nama");
				printf("\n[3]. Stok");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);

				if(pilih == 1)
				{
					printf ("\nMasukan Data Harga Baru : ");fflush(stdin);
					scanf ("%f",&cek.harga);
					fprintf(fpr, "\n%s", ctime(&t));
                    fprintf(fpr, "Mengedit data dengan id %d, harga %.2f menjadi %.2f\n",info.id, info.harga, cek.harga);
					info.harga=cek.harga;
                    fprintf(baru, "%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",info.id, info.namaMenu, info.harga, info.stok, info.jenisMenu);
                    printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Nama Baru  : ");fflush(stdin);
					scanf ("%[^\n]",cek.namaMenu);
					fprintf(fpr, "\n%s", ctime(&t));
                    fprintf(fpr, "Mengedit data dengan id %d, nama %s menjadi %s\n",info.id, info.namaMenu, cek.namaMenu);
					strcpy(info.namaMenu,cek.namaMenu);
                    fprintf(baru, "%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",info.id, info.namaMenu, info.harga, info.stok, info.jenisMenu);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Stok Baru : ");
					scanf ("%d",&cek.stok);
					fprintf(fpr, "\n%s", ctime(&t));
                    fprintf(fpr, "Mengedit data dengan id %d, stok %d menjadi %d\n",info.id, info.stok, cek.stok);
					info.stok = cek.stok;
					fprintf(baru, "%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",info.id, info.namaMenu, info.harga, info.stok, info.jenisMenu);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			 fprintf(baru, "%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",info.id, info.namaMenu, info.harga, info.stok, info.jenisMenu);
		}
	}

	fclose(lama);
	fclose(baru);
	fclose(fpr);
	remove("daftar-menu.txt");
	rename("baru.txt","daftar-menu.txt");
	if(test!=1){
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
    }
    printf("\n\nketik sembarang");
    getch();
}

void cariData(){
    time_t t;
    time(&t);
    FILE *ptr, *fp;
	int test=0;
	system("cls");
	ptr=fopen("daftar-menu.txt","r");
	fp=fopen("riwayat.txt","a");
	system("cls");
	printf("Input ID  : ");
	scanf("%d", &cek.id);fflush(stdin);
	while(fscanf(ptr, "%d %s %f %d %s", &info.id, info.namaMenu, &info.harga, &info.stok, info.jenisMenu)!=EOF)
        {
		if(info.id==cek.id){
			test=1;
			printf ("\nID [%d]",info.id);
			printf("\nNama Menu\t: %s",info.namaMenu);
			printf("\nHarga\t\t: %.2f",info.harga);
			printf("\nStok\t\t: %d",info.stok);
			printf("\nJenis\t\t: %s",info.jenisMenu);
			fprintf(fp, "\n%s", ctime(&t));
            fprintf(fp, "Mencari data dengan id %d, nama %s\n",info.id, info.namaMenu);
		}
	}
	fclose(ptr);
	fclose(fp);
	if(test!=1){
		system("cls");
		printf("\nData tidak ditemukan !\a\a\a");

	}
    printf("\n\nketik sembarang");
    getch();
}

void urutData(){
    time_t t;
    time(&t);
    system("cls");
	FILE *data, *fpr;
	int count = 0,i,j,test=0,pil;
	system("cls");
	printf ("MENAMPILKAN TOTAL NILAI ASCENDING DAN DESCENDING\n");
	data=fopen("daftar-menu.txt","r");
	fpr=fopen("riwayat.txt","a");
	while(fscanf(data, "%d %s %f %d %s", &info.id, info.namaMenu, &info.harga, &info.stok, info.jenisMenu)!=EOF)
    {

		sort[count].harga = info.harga;
		sort[count].id = info.id;
		sort[count].stok = info.stok;
		strcpy(sort[count].namaMenu,info.namaMenu);
		strcpy(sort[count].jenisMenu,info.jenisMenu);
		count++;
		test=1;
	}
	back:
	printf ("\n");
	printf ("1.ASCENDING\n");
	printf ("2.DESCENDING\n");
	printf("\nPilih: ");scanf("%d",&pil);

	if(pil==1)
	{
		system("cls");
		printf("ID\t NAMA MENU\t\t\t HARGA\t\t\t STOK\t\t JENIS\n");
		for(i=0;i<count-1;i++){
			for(j=i+1;j<count;j++)
			{
				if(sort[i].harga > sort[j].harga)
				{
					temp = sort[j];
					sort[j] = sort[i];
					sort[i] = temp;
				}
			}
		}

		for(i=0;i<count;i++)
		{
			printf("%d\t %s\t\t\t %.2f\t\t %d\t\t %s\n",sort[i].id,sort[i].namaMenu,sort[i].harga, sort[i].stok, sort[i].jenisMenu);
		}
            fprintf(fpr, "\n%s", ctime(&t));
            fprintf(fpr, "Mengurutkan data dengan ascending\n");
	}
	else if (pil == 2)
	{
		system("cls");
		printf("ID\t NAMA MENU\t\t\t HARGA\t\t\t STOK\t\t JENIS\n");
		for(i=0;i<count-1;i++){
			for(j=i+1;j<count;j++)
			{
				if(sort[i].harga < sort[j].harga)
				{
					temp = sort[j];
					sort[j] = sort[i];
					sort[i] = temp;
				}
			}
		}
		system("cls");
		printf("ID\t NAMA MENU\t\t\t HARGA\t\t\t STOK\t\t JENIS\n");
		for(i=0;i<count;i++)
		{
			printf("%d\t %s\t\t\t %.2f\t\t %d\t\t  %s\n", sort[i].id,sort[i].namaMenu,sort[i].harga, sort[i].stok, sort[i].jenisMenu);
		}
		fprintf(fpr, "\n%s", ctime(&t));
        fprintf(fpr, "Mengurutkan data dengan descending\n");
	}
	else{
		printf ("Salah INPUT!\n");
		getch();
		goto back;
	}
	fclose(data);
	fclose(fpr);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
    }
     printf("\n\nketik sembarang");
    getch();


}

void SetColor(unsigned short color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput,color);
}

void tampilRiwayat(){
    char baca;
    FILE *fptr;
    system("cls");
    fptr = fopen("riwayat.txt","r");
    if(fptr == NULL){
        printf("\nerr: File tidak ada");
    }
    while((baca = fgetc(fptr))!=EOF){
        putchar(baca);
    }
    fclose(fptr);
    getch();
}



