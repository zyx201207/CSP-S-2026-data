#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],b[500005],t[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n>500)
    {
        for(int i=1;i<=n+1;i++)
        {
            t[a[i]++];
            if(a[i]!=a[i-1])
                b[a[i-1]]=i-1;
        }
        for(int i=2;i<=m+1;i++)
            cout<<b[i]<<" ";
        return 0;
    }
    for(int k=1;k<=n;k++)
    {
        memset(b,500004,0);
        long long x=0;
        for(int j=k;j<=n;j++)
        {
            b[++x]=a[j];
            bool f=false;
            long long x1=x;
            for(int i=1;i<=x1;i++)
            {
                if(f==true)
                {
                    b[i]=0;
                    x--;
                }
                if(b[i]==a[j])
                    f=true;
            }
        }
        for(int j=1;j<=x;j++)
            t[b[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<t[i]<<" ";
    return 0;
}