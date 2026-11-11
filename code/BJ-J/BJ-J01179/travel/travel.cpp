#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d%c %d%d%c",&a,&b,&e,&c,&d,&f);
    if(a!=c){
        printf("0000\n");
    }else if(b!=d){
        printf("1000\n");
    }else if((e>'C'&&f<'D')||(f>'C'&&e<'D')){
        printf("1100\n");
    }else if(f-e==1||e-f==1){
        printf("1111\n");
    }else {
        printf("1110\n");
    }
}