#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[10],s2[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int f3=0;
    if(c1==c2){
        f3=1;
        printf("1");
    }
    else{
        f3=0;
        printf("0");
    }
    if(f3==0){
        printf("000");
        return 0;
    }
    int a=(s1[1]-'0')+(s1[0]-'0')*10;
    int b=(s2[1]-'0')+(s2[0]-'0')*10;
    int f2=0;
    if(a==b){
        f2=1;
        printf("1");
    }
    else{
        f2=0;
        printf("0");
    }
    char x=s1[2],y=s2[2];
    int f=0;
    if(f2==1){
        if((x<='C'&&x>='A'&&y<='C'&&y>='A')||(x>='D'&&x<='F'&&y>='D'&&y<='F')){
            printf("1");
            f=1;
        }
        else{
            printf("0");
            f=0;
        }
    }
    else{
        f=0;
        printf("0");
    }
    if(f==1){
        if(abs(x-y)==1||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    else{
        printf("0");
    }
    return 0;
}
