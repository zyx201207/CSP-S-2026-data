#include<bits/stdc++.h>
using namespace std;
int main(){

    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);

    char a[12],b;
    scanf("%c",&b);
    int j=0;
    while(b!='\n'){
        if(b!=' '){
            a[j]=b;
            j++;
        }
        scanf("%c",&b);
    }
    a[j]='\0';


    int e=0;

    if(a[0]==a[5] && a[1]==a[6]){
        printf("1");
    }
    else{
        printf("0000");
        return 0;
    }
    if(a[2]==a[7] && a[3]==a[8]){
        printf("1");
    }
    else{
        printf("000");
        return 0;
    }
    //
    if(a[4]>='A' && a[4]<='C' && a[9]>='A' && a[9]<='C'){
        printf("1");
    }
     else if(a[4]>='D' && a[4]<='F' && a[9]>='D' && a[9]<='F'){
            if(a[4]!='E' && a[9]!='E'){
                printf("11");
                return 0;
            }
    }
    else{
        printf("00");
        return 0;
    }

    if(a[4]=='A' && a[9]=='C' || a[4]=='C' && a[9]=='A'){
        printf("0");
        return 0;
    }
    printf("1");
    return 0;
}
