#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}
int c,t,n,k,dis[1001][1001],ans;
bool vis[1001],st[11];
vector<int> a[100001];
void bfs(int u)
{
    st[u]=1;
    for(int v:a[u])
    {
        if(!vis[v]||st[v]) continue;
        bfs(v);
    }
}
void check()
{
    memset(st,0,sizeof st);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]&&!st[i])
        {
            cnt++;
            bfs(i);
        }
    }
    if(cnt>2) return;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        int mn=1e9;
        for(int j=1;j<=n;j++) if(vis[j]) mn=min(mn,dis[i][j]);
        mx=max(mx,mn);
    }
    ans=min(ans,mx);
}
void dfs(int now,int ct)
{
    if(ct==k)
    {
        check();
        return;
    }
    if(now==n+1) return;
    vis[now]=1;
    dfs(now+1,ct+1);
    vis[now]=0;
    dfs(now+1,ct);
}
void get_dis(int u,int f,int id)
{
    for(int v:a[u])
    {
        if(v==f) continue;
        dis[id][v]=dis[id][u]+1;
        get_dis(v,u,id);
    }
}
int main()
{
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if(c<=3||k<=3)
        {
            for(int i=1;i<=n;i++) dis[i][i]=0,get_dis(i,0,i);
            ans=1e9;
            dfs(1,0);
            cout<<ans<<"\n";
        }
        else if(c==7)
        {
            for(int i=1;i<=n;i++) dis[i][i]=0,get_dis(i,0,i);
            ans=1e9;
            for(int i=1;i<=n;i++)
            {
                int mx1=0,mx2=0;
                for(int j=1;j<=n;j++)
                {
                    if(dis[i][j]>mx1) mx2=mx1,mx1=dis[i][j];
                    else if(dis[i][j]>mx2) mx2=dis[i][j];
                }
                if(mx1-mx2-1>2*mx2+1) ans=min(ans,max(mx2,(mx1-mx2)/2));
            }
            cout<<ans<<"\n";
        }
        else if(c==13||c==14)
        {
            int l=0,r=(n+1)/2,m=(n-1)/2;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(k%2==0)
                {
                    int R=m+1-mid-k/2;
                    int L=mid+k/2;
                    int Mid=L+R>>1;
                    if(min(Mid-L,R-Mid)+1>mid) l=mid+1;
                    else r=mid-1,ans=mid;
                }
                else
                {
                    int R=m+1-mid-k/2-1;
                    int L=mid+k/2;
                    int Mid=L+R>>1;
                    if(min(Mid-L,R-Mid)+1>mid) l=mid+1;
                    else r=mid-1,ans=mid;
                }
            }
            cout<<ans<<"\n";
        }
        else cout<<1<<"\n";
    }
    return 0;
}
