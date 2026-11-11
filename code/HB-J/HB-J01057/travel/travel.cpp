#include<bits/stdc++.h>
using namespace std;
int guodao(char a){
    if(a=='A'||a=='B'||a=='C'){
        return 1;
    } else {
        return 0;
    }
}
int xianglin(char a,char b){
    if(a=='A'&&b=='B'){
        return 1;
    }
    if(a=='C'&&b=='B'){
        return 1;
    }
    if(a=='B'&&b=='A'){
        return 1;
    }
    if(a=='B'&&b=='C'){
        return 1;
    }
    if(a=='D'&&b=='F'){
        return 1;
    }
    if(a=='F'&&b=='D'){
        return 1;
    }
    return 0;
}
int main(){
    char tra[10];
    bool flag=1;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%c%c %c%c%c %c%c %c%c%c",&tra[0],&tra[1],&tra[2],&tra[3],&tra[4],&tra[5],&tra[6],&tra[7],&tra[8],&tra[9]);
    if(tra[0]==tra[5]&&tra[1]==tra[6]){
        printf("1");
    } else {
        printf("0");
        flag=0;
    }
    if(tra[2]==tra[7]&&tra[3]==tra[8]&&flag){
        printf("1");
    } else {
        printf("0");
        flag=0;
    }
    printf("%d",guodao(tra[4])==guodao(tra[9])&&flag);
    if(!guodao(tra[4])==guodao(tra[9])){
        flag=0;
    }
    printf("%d",xianglin(tra[4],tra[9])&&flag);
    return 0;
}
