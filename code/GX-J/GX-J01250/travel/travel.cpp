#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    int a,b;
    char x;
    char y;
    cin>>n>>a>>x>>m>>b>>y;
    int flag=0;
    if(n==m){
        cout<<1;
        flag=1;
    }else{
        cout<<0;
    }
    if(a==b&&flag==1){
        cout<<1;
        flag=2;
    }else{
        cout<<0;
    }
    if((((x=='A'||x=='B')||x=='C')&&((y=='A'||y=='B')||y=='C'))&&flag==2){
        cout<<1;
        flag=3;
    }else if((x=='D'||x=='F')&&(y=='D'||y=='F')){
        cout<<1;
        flag=3;
    }else{
        cout<<0;
    }
    int sum=x-y;
    if(((sum==1||sum==-1)&&(x!='C'&&y!='D'))&&flag==3){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
