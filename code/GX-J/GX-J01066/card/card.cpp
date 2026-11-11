#include<bits/stdc++.h>
using namespace std;
int a[500005];
int p[500005];
int u[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n-1;i++)
    {
        int s[500005]={};
        bool k[300005]={};
        for(int j=i;j<=n-1;j++)
        {
            s[j-i]=a[j];
            p[a[j]]=j-i;
            if(k[a[j]]==1)
            {
                for(int w=p[a[j]];w<=(j)-p[a[j]];w++)
                {
                    s[w]=0;
                }

            }
            k[a[j]]=1;
        }
        for(int d=1;d<=m;d++)
        {
            for(int j=0;j<=n;j++)
            {
                if(s[j]==d)
                {
                    u[d]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<u[i]<<" ";
    return 0;
}
