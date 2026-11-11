#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=1005;
int n,d;
ll a[N];
ll cnt[N],dis[N];
void dfs(int p)
{
    for(int i=p+1;i<=n;i++)
    {
        if(a[i]-a[p]>d) break;
        if(dis[p]+1<dis[i])
        {
            cnt[i]=1;
            dis[i]=dis[p]+1;
            dfs(i);
        }
        else if(dis[p]+1==dis[i])
        {
            cnt[i]+=cnt[p];
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(dis,0x3f,sizeof dis);
        memset(cnt,0,sizeof cnt);
        cnt[i]=1;
        dis[i]=0;
        dfs(i);
        for(int j=i+1;j<=n;j++)
        {
            if(cnt[j]==2) ++ans;
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}