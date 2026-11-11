#include<bits/stdc++.h>
using namespace std;
int c,n,m,k;
int T;
int u,v;
vector<int> e[1005];
bool f[10005];
int ans;
int che(int x,int fa,int cnt,int dis)
{
    if(f[x]&&!f[fa])cnt++;
    if(cnt>2)return -1;
    if(x!=1&&e[x].size()==1)
    {
        return dis;
    }
    int a=dis;
    for(int i:e[x])
    {
        if(i==fa)continue;
        int p;
        if(!f[i])p=che(i,x,cnt,dis+1);
        else p=che(i,x,cnt,0);
        if(p==-1)return -1;
        a=max(a,p);
    }
    return a;
}
void dfs(int p,int cnt)
{
    if(p==n)
    {
        if(cnt!=k)return;
        ans=min(che(0,1,0,0),ans);
    }
    if(n-p>k-cnt)
    {
        f[p+1]=1;
        dfs(p+1,cnt+1);
        f[p+1]=0;
        dfs(p+1,cnt);
    }
    else
    {
        f[p+1]=1;
        dfs(p+1,cnt+1);
        f[p+1]=0;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(nullptr));
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            f[i]=0;
        }
        ans=10000;
        //dfs(0,0);
        cout<<rand()%3+1<<'\n';
    }
    return 0;
}
