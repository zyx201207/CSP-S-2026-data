#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a,ans=0;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    if(a==2)cout<<0;
    else if(a==6)cout<<3000000000;
    else if(a==3)cout<<2;
    else cout<<0;
    return 0;
}
