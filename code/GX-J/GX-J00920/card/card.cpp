#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[50001],c[50001],w[50001],h[50001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    cin>>a[i];
    }
    int z=1;
    for(int i=1;i<=n;i++)
    {
        if(c[a[i]]==0)
        {
        c[a[i]]++;
        }
        else
        {
            while(b[z]!=a[i])
            {
            b[z]=0;
            z--;
            }
        }
        b[z]=a[i];
        z++;
        for(int j=1;j<=z;j++)
        {
            h[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
    cout<<h[i]<<" ";
    }
    return 0;
}

