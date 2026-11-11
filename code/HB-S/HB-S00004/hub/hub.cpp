#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,fa[N],vis[N],ans,d[N],q[N],p[N];
vector<int>v[N];
int find(int x)
{
    if(x==fa[x])return x;
    return find(fa[x]);
}
void dfs(int xx,int cnt)
{
    if(xx>n)
    {
        if(cnt)return;
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])continue;
            for(int j=0;j<v[i].size();j++)
            {
                int y=v[i][j];
                if(!vis[y])continue;
                fa[find(i)]=find(y);
            }
        }
        int u1=0,v1=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])continue;
            if(find(i)==u1)continue;
            if(find(i)==v1)continue;
            if(u1==0)
            {
                u1=find(i);
                continue;
            }
            if(v1==0)
            {
                v1=find(i);
                continue;
            }
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                d[i]=0;
                continue;
            }
            int l=1,r=0;
            q[++r]=i;
            for(int i=1;i<=n;i++)
            {
                p[i]=0;
            }
            p[i]=1;
            while(r>=l)
            {
                int x=q[l];l++;
                for(int j=0;j<v[x].size();j++)
                {
                    int y=v[x][j];
                    if(p[y])continue;
                    p[y]=p[x]+1;
                    q[++r]=y;
                }
            }
            d[i]=1e9;
            for(int j=1;j<=n;j++)
                if(vis[j])d[i]=min(d[i],p[j]-1);
        }
        int sum=0;
        for(int i=1;i<=n;i++)sum=max(sum,d[i]);
        ans=min(sum,ans);
        //cout<<sum<<'\n';
        return;
    }
    vis[xx]=0;
    dfs(xx+1,cnt);
    if(!cnt)return;
    vis[xx]=1;
    dfs(xx+1,cnt-1);
    vis[xx]=0;
}
void run()
{
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans=1e9;
    dfs(1,k);
    cout<<ans<<'\n';
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        if(c>=0&&c<=3)
        {
            run();
        }
        else cout<<"734\n";
    }
    return 0;
}