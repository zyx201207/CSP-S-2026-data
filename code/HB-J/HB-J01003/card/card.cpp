#include<bits/stdc++.h>
using namespace std;
int b[500005];
int a[300005];
int d[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,o=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(d,0,o);
        o=0;
        for(int j=i;j<=n;j++)
        {
            o++,d[o]=b[j];
            for(int q=1;q<o;q++)
            {
                if(d[q]==d[o])
                {
                    o=q;
                    break;
                }
            }
        }
        for(int j=1;j<=o;j++)
        {
            a[d[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
