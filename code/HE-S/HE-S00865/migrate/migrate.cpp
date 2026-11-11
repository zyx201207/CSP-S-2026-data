#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int a[2000010],nxt[1000010];
int dis[5010],cnt[5010];
bool vis[5010];
int bfs(int s)
{
    int ans=0;
    fill(dis,dis+n+5,0x3f3f3f3f);
    fill(cnt,cnt+n+5,0);
    fill(vis,vis+n+5,0);
    queue<int> q;
    q.push(s);
    cnt[s]=1,dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=u+1;a[i]-a[u]<=d and i<=n;i++)
        {
            if(dis[i]>dis[u]+1)
            {
                dis[i]=dis[u]+1;
                cnt[i]=1;
                q.push(i);
            }
            else if(dis[i]==dis[u]+1)
                cnt[i]+=cnt[u];
        }
    }
    for(int i=s;i<=n;i++)
        if(cnt[i]==2)ans++;
        return ans;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c;
    if(c<=10)
    {
        cin>>t;
        while(t--)
        {
			cin>>n>>d;
    	    int ans=0;
    	    for(int i=1;i<=n;i++)cin>>a[i];
    	    for(int i=1;i<=n;i++)ans+=bfs(i);
    	    cout<<ans;
		}
    }
    else if(c>=15 and c<=18)
    {
        cin>>t;
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int i=1;i<=n;i++)nxt[i]=upper_bound(a+i+1,a+n+1,a[i]+d)-1-a;
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                int r=i,lst=i-1;
                while(r<n and r!=lst)
                {
                    if(r-lst>=2)ans+=nxt[r-1]-r;
                    lst=r;
                    r=nxt[r];
                }
            }
            for(int i=1;i<=n;i++)
            {
                int r=i,lst=i-1;
                while(r<n and r!=lst)
                {
                    if(r-lst>=3)ans-=nxt[r-2]-r;
                    lst=r;
                    r=nxt[r];
                }
            }
            cout<<ans<<'\n';
        }
    }
}
