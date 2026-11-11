#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000005];
bool f[5005][5005];
int x[5005][5005];
struct node
{
    int u,v,w;
};
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    cin>>c;
    int T;
    cin>>T;
    while(T--)
    {
        memset(f,0,sizeof(f));
        memset(x,0,sizeof(x));
        cin>>n;
        long long d;
        cin>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n<=5000)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j]-a[i]<=d)
                    {
                        f[i][j]=1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            int ans=0;
            for(int i=2;i<n;i++)
            {
                for(int j=1;j<i;j++)
                {
                    for(int k=i+1;k<=n;k++)
                    {
                        if(f[j][i]&&f[i][k]&&f[j][k]==0)
                        {
                            x[j][k]++;
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(x[i][j]==2)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
