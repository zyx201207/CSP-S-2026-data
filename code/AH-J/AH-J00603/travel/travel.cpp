#include<bits/stdc++.h>
using namespace std;
int aa,bb;
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>aa>>a>>bb>>b;
    if(aa!=bb){
        printf("0000");
        return 0;
    }
    printf("1");
    int m=(a[0]-'0')*10+a[1]-'0',n=(b[0]-'0')*10+b[1]-'0';
    if(m!=n){
        printf("000");
        return 0;
    }
    printf("1");
    char x=a[2],y=b[2];
    if((x=='F'||x=='D')&&(y=='F'||y=='D')){
        printf("11");
        return 0;
    }
    if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))printf("1");
    else {printf("00");return 0;}
    if(abs(x-y)==1)printf("1");
    else printf("0");
    return 0;
}
