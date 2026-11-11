#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
const int N=1e6+10;

struct bian
{
    int data;
    int nex;
}e[N<<1];
int head[N],cnt,n,m;
int f[N],g[N],vis[N];

void read() {}
template <typename T,typename ...Args>
void read(T &x,Args &...args)
{
    x=0;  char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    read(args...);
}

inline void add(int x,int y) {e[++cnt].data=y;  e[cnt].nex=head[x];  head[x]=cnt;}

void dfs(int x,int now,int before,int deep)
{
    if(f[x]) return g[now]=min(g[now],deep),void();
    for(int i=head[x];i;i=e[i].nex)
        if(e[i].data!=before) dfs(e[i].data,now,x,deep+1);
}

void check(int x,int before)
{
    vis[x]=1;
    for(int i=head[x];i;i=e[i].nex)
        if(e[i].data!=before&&f[e[i].data]) check(e[i].data,x);
}

void dfs1(int x,int before,int deep)
{
    g[x]=min(g[x],deep);
    for(int i=head[x];i;i=e[i].nex)
    {
        if(e[i].data==before) continue;
        dfs1(e[i].data,x,deep+1);
    }
}

inline void subtask1()
{
    int S=(1<<n)-1,ans=n,maxn,cnt;
    for(int i=1;i<=S;i++)
    {
        if(__builtin_popcount(i)!=m) continue;
        for(int j=0;j<n;j++) f[j+1]=(i>>j)&1,vis[j+1]=0;
        maxn=cnt=0;
        for(int j=1;j<=n;j++)
            if(f[j]&&!vis[j]) check(j,0),cnt++;
        if(cnt>2) continue;
        for(int j=1;j<=n;j++)
            if(!f[j]) g[j]=n,dfs(j,j,0,0),maxn=max(maxn,g[j]);
        ans=min(ans,maxn);
    }
    printf("%d\n",ans);
}

void solve()
{
    int x,y;  read(n,m);  cnt=0;
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<n;i++) read(x,y),add(x,y),add(y,x);
    if(n<=10) return subtask1();
    else
    {
        // clock_t start=clock();
        int ans=n,maxn;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=1;k<=n;k++) g[k]=n;
                dfs1(i,0,0);  dfs1(j,0,0);  maxn=0;
                for(int k=1;k<=n;k++) maxn=max(maxn,g[k]);
                ans=min(ans,maxn);
                // clock_t lst=clock();
                // if(1.0*(lst-start)<=2.95) break;
            }
            // clock_t lst=clock();
            // if(1.0*(lst-start)<=2.95) break;
        }
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int abc,t;  read(abc,t);
    while(t--) solve();
    return 0;
}