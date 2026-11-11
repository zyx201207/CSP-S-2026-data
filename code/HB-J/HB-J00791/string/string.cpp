#include<bits/stdc++.h>
using namespace std;
char s[500];
int f(int *a,int st,int en){
    int s=0,ma=2e9;
    for(int i=0;i<(en-st)/2;i++){
        for(int j=0;j<=i;j++)
            if(a[j]!=a[en-st+2-j]) s++;
        if(s<ma) s+=f(a,i+1,en-i-1);
        if(s<ma) ma=s;
    }
    return ma;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int l,x,k=0;
    char c;
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        scanf("%d",&x);
        for(int j=0;j<x,j++){
            if(k==n+1) break;
            scanf("%c",&c);
            k++;
        }
    }
    f(s,0,k);
    printf("%d",ma);
    return 0;
}
