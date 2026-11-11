#include<iostream>
#include<cstring>
using namespace std;

char a[10];
char b[10];
char c[10];
char d[10];
char e[10];
char f[10];
int num[10];

bool check(char ch1,char ch2){
    if('A'<=ch1&&'C'>=ch1){
        if('A'<=ch2&&'C'>=ch2){
            if(ch1=='B'||ch2=='B'){
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool j=false;
    if(ch1=='D'){
        if(ch2=='F'){
            j=true;
        }
    }
    if(ch1=='F'){
        if(ch2=='D'){
            j=true;
        }
    }
    if(j==true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(strcmp(a,c)==0){
        printf("1");
    }
    else{
        printf("0000");
        return 0;
    }
    for(int i=0;i<2;i++){
        e[i]=b[i];
    }
    for(int i=0;i<2;i++){
        f[i]=d[i];
    }
    if(strcmp(e,f)==0){
        printf("1");
    }
    else{
        printf("000");
        return 0;
    }
    char ch1=b[2];
    char ch2=d[2];
    bool j1=true;
    if('A'<=ch1&&'C'>=ch1){
        if('A'<=ch2&&'C'>=ch2){
            j1=false;
            printf("1");
        }
    }
    if('D'==ch1||'F'==ch1){
        if('D'==ch2||'F'==ch2){
            j1=false;
            printf("1");
        }
    }
    if(j1==true){
        printf("00");
        return 0;
    }
    if(check(ch1,ch2)==true){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}
