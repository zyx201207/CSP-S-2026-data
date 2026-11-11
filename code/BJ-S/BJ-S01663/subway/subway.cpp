#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,C,d,q,w[N],tot,K[N];
long long f[2005][2005];
inline void add(int x,int y,int z)
{
    f[x][y]=f[y][x]=z;
}
inline int readint()
{
    int k=0,f=1,c=getchar_unlocked();
    for(;!isdigit(c);c=getchar_unlocked()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar_unlocked()) k=k*10+(c^48); 
    return k*f;
}
namespace FY
{
    inline void floyd()
    {
        for(int k=1;k<=tot;++k) 
        {
            for(int i=1;i<=tot;++i) 
            {
                for(int j=1;j<=tot;++j) 
                {
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
    }
    inline void init()
    {
        memset(f,0x3f,sizeof(f));
        tot=m<<1;
        for(int i=1;i<=n;++i) 
        {
            K[i]=readint();
            int cur,x;
            if(C>=9&&C<=11)
            {
                if(K[i]==1) continue;
                int p,u;//cin>>cur>>x>>p>>u;
                cur=readint();x=readint();
                p=readint();u=readint();
                add(cur+m,p+m,x+u);
            }
            else
            {
                for(int j=1;j<=K[i];++j) 
                {
                    //cin>>cur>>x;
                    cur=readint();
                    x=readint();
                    add(cur+m,tot+i,x);//car tot+i
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            add(i,i+m,w[i]);//ting&&tai
        }
        if(C<9||C>11) tot+=n;
        floyd();
        for(int i=1;i<=q;i++) 
        {
            int x,y;x=readint();y=readint();
            cout<<f[x][y]<<"\n";
        }
    }
    
}
namespace SUB_B
{
    struct D
    {
        int v,w;
    };
    vector <D> G[N];
    long long vis[N];
    inline void bfs(int s,int t)
    {
        queue <int> q;
        q.push(s);
        while(!q.empty())
        {
            
            int u=q.front();
            q.pop();
            if(u==t)
            {
                cout<<(long long)(w[s]+w[t]+vis[u])<<"\n";
                break;
            }
            for(auto k:G[u])
            {
                if(k.v==s||vis[k.v]) continue;
                q.push(k.v);vis[k.v]=vis[u]+k.w;
            }
        }
    }
    inline void init()
    {
        for(int i=1;i<=n;i++) 
        {
            // cin>>K[i];
            K[i]=readint();
            int cur,x;
            for(int j=1;j<=K[i];j++) 
            {
               // cin>>cur>>x;
                cur=readint();x=readint();
                G[cur].push_back({i+m,x});
                G[i+m].push_back({cur,x});
            }
        }
        for(int i=1;i<=q;i++) 
        {
            memset(vis,0,sizeof(vis));
            int l,r;//cin>>l>>r;
            l=readint();r=readint();
            bfs(l,r);
        }   
    }
    
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   // cin>>C>>n>>m>>d>>q;
    C=readint();n=readint();m=readint();
    d=readint();q=readint();
    for(int i=1;i<=m;++i)
    {
        w[i]=readint();
      //  cin>>w[i];
    } 
    if(C&&C<=11||C>=20) FY::init();
    else SUB_B::init();
    return 0;   
}