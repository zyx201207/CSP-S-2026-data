#include <bits/stdc++.h>
using namespace std;
long long n;
string a=" ";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=-1;
    if(n==1){
        cout<<0;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        long long op;
        char sr;
        cin>>op>>sr;
        for(int j=1;j<=op;j++)
        {
            a[++cnt]=sr;
        }
    }
    int ct=0;
    for(int i=0;i<=cnt/2;i++)
    {
        int j=cnt-i;
        if(a[i]!=a[j]) ct++;
    }
    cout<<ct;
}
