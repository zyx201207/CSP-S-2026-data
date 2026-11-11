#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char ss1,ss2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d%c%d%d%c",&c1,&s1,&ss1,&c2,&s2,&ss2);
    if(c1==c2){
        printf("1");
        if(s1==s2){
            printf("1");
            if('A'<=ss1&&ss1<='C'&&'A'<=ss2&&ss2<='C'){
                printf("1");
            }else if('D'<=ss1&&ss1<='F'&&'D'<=ss2&&ss2<='F'){
                printf("1");
            }else{
                printf("00\n");
                return 0;
            }
            if(ss1=='A'&&ss2=='B'){
                printf("1");
            }else if(ss1=='B'&&ss2=='C'){
                printf("1");
            }else if(ss1=='D'&&ss2=='F'){
                printf("1");
            }else if(ss1=='F'&&ss2=='D'){
                printf("1");
            }else if(ss1=='C'&&ss2=='B'){
                printf("1");
            }else if(ss1=='B'&&ss2=='A'){
                printf("1");
            }else{
                printf("0");
            }
            printf("\n");
        }else{
            printf("000\n");
        }
    }else{
        printf("0000\n");
    }
}