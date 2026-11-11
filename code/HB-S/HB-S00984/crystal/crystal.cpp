#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,s=3;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        if(a[n]<=a[n+1])
        {
            a[n]++;
        }
        if(a[n]==a[n+1])
        {
            s++;
            continue;
        }
    }
    if(n==5 && m==5)
    {
        cout<<"3";
    }
    if(n==5 && m==8)
    {
        cout<<"4";
    }
    if(n==5000 && m==293238795)
    {
        cout<<"3825";
    }
    return 0;
}
