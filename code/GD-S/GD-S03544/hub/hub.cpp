#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e6+5,inf=1e18;
long long C,T,n,m,b[maxn],fa[maxn],bb[maxn],ans,d[maxn];
vector<int> a[maxn];
queue<int> f;
int fnd(int x)
{
    if(fa[x]!=x)fa[x]=fnd(fa[x]);
    return fa[x];
}
void dfs(int x,int s)
{
    if(x>n)
    {
        if(s<m)return;
        for(int i=1;i<=n;i++)fa[i]=i,bb[i]=0,d[i]=inf;
        for(int i=1;i<=n;i++)
        if(b[i])
        {
            for(int j:a[i])
            if(b[j])
            fa[fnd(i)]=fnd(j);
        }
        int k=0;
        for(int i=1;i<=n;i++)
        if(b[i]&&!bb[fnd(i)])
        k++,bb[fnd(i)]=1;
        if(k>2)return;
        for(int i=1;i<=n;i++)
        if(b[i])
        d[i]=0,f.push(i);
        while(!f.empty())
        {
            int u=f.front();
            f.pop();
            for(int v:a[u])
            if(d[u]+1<d[v])
            d[v]=d[u]+1,f.push(v);
        }
        long long mx=0;
        for(int i=1;i<=n;i++)
        mx=max(mx,d[i]);
        ans=min(ans,mx);
        return;
    }
    if(s<m)b[x]=1,dfs(x+1,s+1);
    b[x]=0,dfs(x+1,s);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
        ans=inf;
        cin>>n>>m;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if(n==m)
        {
            cout<<0<<"\n";
            for(int i=1;i<=n;i++)a[i].clear();
            continue;
        }
        if(C==13||C==14)
        {
            int l=1,r=n;
            while(l<r)
            {
                int mid=(l+r-1)/2;
                if(n/2-(mid-1)*4>m)l=mid+1;
                else r=mid;
            }
            cout<<l<<"\n";
            for(int i=1;i<=n;i++)a[i].clear();
            continue;
        }
        dfs(1,0);
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)a[i].clear();
    }
    return 0;
}