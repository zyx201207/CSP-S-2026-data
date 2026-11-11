#include <bits/stdc++.h>
using namespace std;
char a[10];
char b[10];
char c[10];
char d[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s",a+1);
    scanf("%s",b+1);
    scanf("%s",c+1);
    scanf("%s",d+1);
    if(a[1]==c[1]&&a[2]==c[2]){
        printf("1");
    }else{
        printf("0000");
        return 0;
    }

    if(b[1]==d[1]&&b[2]==d[2]){
        printf("1");
    }else{
        printf("000");
        return 0;
    }

    if((b[3]<='C'&&d[3]<='C')||(b[3]>='D'&&d[3]>='D')){
            printf("1");
    }else{
        printf("00");
        return 0;
    }

    if(b[3]-d[3]==1||b[3]-d[3]==-1){
        printf("1");
    }else{
        printf("0");
    }
	return 0;
}
