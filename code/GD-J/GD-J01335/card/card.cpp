#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int f[300005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        int b[500005];
        for(int j=i;j<=n;++j)
        {
            b[j]=a[j];
        }
        for(int j=i;j<=n;++j)
        {
            //bool flag=false;
            for(int k=i;k<j;++k)
            {
                if(b[k]==b[j]&&b[k]!=0)
                {
                    for(int o=k;o<j;++o)
                    {
                        b[o]=0;
                    }
                    break;
                }
            }
        }

        for(int j=i;j<=n;++j)
        {
            ++f[b[j]];
            //cout<<b[j]<<' '<<f[b[j]]<<endl;
        }
    }
    for(int i=1;i<=m;++i)
    {
        cout<<f[i]<<' ';
    }
    return 0;
}
