#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long k[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long h=0;
    long long p=1,q=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
            p=0;
    }
    if(p)
        cout<<min(n,m+1);
    for(int i=3;i<=n;i++)
        if(a[i]-a[i-1]!=a[i-1]-a[i-2])
            q=0;
    if(q)
        cout<<min(n,m/(a[2]-a[1])+1);
    for(int i=2;i<=n;i++)
    {
        k[i]=k[i-1]+a[i]-a[i-1];
        if(abs(k[i])<=m)
            h++;
    }
    cout<<h+1;
    return 0;
}
