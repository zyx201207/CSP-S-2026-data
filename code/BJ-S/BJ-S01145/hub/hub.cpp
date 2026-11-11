#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,k,c,t;
int vit[N];
struct Edge
{
    int v,nxt;
} e[2*N];
int head[N],cnt;
void add(int u,int v)
{
    cnt++;
    e[cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
int zu[N];
void dfs(int u,int fa)
{
    if(vit[u] && vit[fa]) zu[u]=zu[fa];
    else if(vit[u]) zu[u]=u;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
    }
}
int logn;
int f[N][22],dep[N];
void df(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=logn;i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa) continue;
        df(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    //cout<<x<<" "<<y<<" ";
    for(int i=logn;i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    //cout<<x<<" "<<y<<" ";
    if(x==y) return x;
    for(int i=logn;i>=0;i--)
    {
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    //cout<<f[x][0]<<"\n";
    return f[x][0];
}
int let(int x,int y)
{
    int lc=lca(x,y);
    return dep[x]-dep[lc]+dep[y]-dep[lc];
}
map<int,int> mp;
int cc[N],ccnt,ans;
void fenzhi(int nw,int sum)
{
    if(nw>=n)
    {
        if(sum>k) return ;
        mp.clear();
        dfs(1,0);
        int jid=0;
        ccnt=0;
        for(int i=1;i<=n;i++)
        {
            if(vit[i])
            {
                cc[++ccnt]=i;
                if(!mp[zu[i]]) jid++,mp[zu[i]]=1;
            }
        }
        if(jid>2) return ;
        int ll=0;
        for(int i=1;i<=n;i++)
        {
            int le=n;
            for(int j=1;j<=ccnt;j++)
            {
                int len=let(i,cc[j]);
                le=min(le,len);
                //cout<<cc[j]<<" "<<i<<" "<<len<<" "<<lca(cc[j],i)<<"\n";
            }
            ll=max(ll,le);
        }
        ans=min(ans,ll);
        return ;
    }
    vit[nw+1]=1;
    fenzhi(nw+1,sum+1);
    vit[nw+1]=0;
    fenzhi(nw+1,sum);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        logn=(log(n)/log(2));
        cnt=0;
        for(int i=1;i<=n;i++) head[i]=0;
        //logn++;
        ans=n;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v),add(v,u);
        }
        df(1,0);
        fenzhi(0,0);
        //cout<<"\n";
        //cout<<lca(1,3)<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}
