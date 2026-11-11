#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int N=1e9+5;
int a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,p=0,q=0,C=0;cin>>n;
    char c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(C==c)
         q++;
		C=c;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])
            p++;}
    if(p==(n-1))
    {
        cout<<n/2;
        return 0;
    }
    if(q==(n-1))
    {
        cout<<"0";
    }
    else
        cout<<"1";
    return 0;
}
