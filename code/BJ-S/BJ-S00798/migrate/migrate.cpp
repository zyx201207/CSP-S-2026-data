#include <bits/stdc++.h>
using namespace std;
const int N=5005;
long long c,T,n,d,a[N],minn,minx,ans;
void dfs(long long now,long long end,long long cnt)
{
    if(now==end)
    {
        if(cnt<minn)
        {
            minn=cnt;
            minx=1;
        }
        else if(cnt==minn) minx++;
        return;
    }
    for(int i=now+1;a[i]-a[now]<=d&&i<=end;i++)
    {
        dfs(i,end,cnt+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                minn=1e9,minx=0;
                dfs(i,j,0);
                if(minx==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}