#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
typedef pair<int,int> pii;
const int _mxn=1e6+10;
int n,k;
vector<int> g[_mxn];
struct dsu
{
    int f[_mxn];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            f[i]=i;
    }
    int find(int x)
    {
        if(f[x]==x)
            return f[x];
        return f[x]=find(f[x]);
    }
    void merge(int x,int y)
    {
        int fx=find(x),fy=find(y);
        if(fx!=fy)
            f[fy]=fx;
    }
    bool same(int x,int y){return find(x)==find(y);}
}st;
inline int getbit(int x,int b){return (x>>b)&1;}
inline int popcount(int x)
{
    int res=0;
    while(x>0)
    {
        res+=x&1;
        x>>=1;
    }
    return res;
}
int d[_mxn];
bool vis[_mxn];
int dis(int x,int mask)
{
    for(int i=1;i<=n;i++)
        vis[i]=false;
    queue<pii> q;
    q.push(make_pair(x,0));
    vis[x]=true;
    while(!q.empty())
    {
        auto cur=q.front();q.pop();
        int u=cur.first,s=cur.second;
        if(getbit(mask,u-1))
            return s;
        for(int v:g[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                q.push(make_pair(v,s+1));
            }
        }
    }
    return -1;
}
int main()
{
    ___();
    int __,_;
    cin>>__>>_;
    while(_--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v),g[v].push_back(u);
        }
        int ans=67676767;
        for(int mask=(1<<k)-1;mask<(1<<n);mask++)
        {
            if(popcount(mask)!=k)
                continue;
            st.init(n);
            for(int i=1;i<=n;i++)
            {
                if(getbit(mask,i-1))
                    for(int v:g[i])
                        if(getbit(mask,v-1))
                            st.merge(i,v);
            }
            set<int> tmp;
            for(int i=1;i<=n;i++)
            {
                if(getbit(mask,i-1))
                    tmp.insert(st.find(i));
            }
            if(tmp.size()>2)
                continue;
            int res=0;
            for(int i=1;i<=n;i++)
            {
                if(!getbit(mask,i-1))
                {
                    res=max(res,dis(i,mask));
                }
            }
            // cout<<res<<" ";
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}