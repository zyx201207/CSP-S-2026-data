#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool a[N][31];
bool vis[N];
bool flag[N];
int sum[31];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(vis,true,sizeof(vis));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<=30;j++)
        {
            a[i][j]=((x>>j)&1);
            sum[j]+=(int)a[i][j];
        }
    }
    int high=-1;
    for(int i=30;i>=0;i--)
    {
        if(sum[i]>=m)
        {
            high=i;
            break;
        }
    }
    int ans=0;
    for(int i=high;i>=0;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[j])
            {
                cnt+=(int)a[j][i];
            }
        }
        if(cnt>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j][i]==0)
                {
                    vis[j]=false;
                }
            }
            ans+=(1<<i);
        }
    }
    cout<<ans;
    return 0;
}
