#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200007];
int dp[200007];
int h[200007];
int b[200007];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int o=n;
    for(int x=1;x<=o;x++)
    {
        memset(b,0,sizeof(b));
        int u=0;
        for(int i=x;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(b[j]==a[i])
                {
                    for(int k=j;k<=u;k++)
                    {
                        b[k]=0;
                    }
                    break;
                }
            }
            u++;
            b[u]=a[i];
            //for(int i=1;i<=u;i++)
            //{
              //  cout<<b[i]<<' ';
           // }
            //cout<<endl;
        }
        for(int i=1;i<=u;i++)
        {
            h[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<h[i]<<' ';
    }
    return 0;
}
