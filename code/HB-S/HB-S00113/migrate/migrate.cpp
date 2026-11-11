#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e6+10;
typedef long long LL;

int n,L[N],f[N],g[N];
LL d,pos[N];

void read() {}
template <typename T,typename ...Args>
void read(T &x,Args &...args)
{
    x=0;  int f=1;  char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;  ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    x*=f;  read(args...);
}

void subtaskA()
{
    LL cnt=d/(pos[2]-pos[1]),ans=0;
    int x=n-cnt-(cnt-1);
    if(x<=0||cnt<=1) puts("0");
    else printf("%d\n",x);
}

void subtaskB()
{
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=d);
    if(cnt>=3) puts("0");
    else if(cnt==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=d) continue;
            int x=lower_bound(pos+1,pos+1+n,pos[i]-d)-pos;
            int y=upper_bound(pos+1,pos+1+n,pos[i]+d)-pos-1;
            L[x]=max(L[x],y);
        }
        for(int i=1;i<=n;i++) L[i]=max(L[i],L[i-1]);
        LL ans=0;
        for(int i=1;i<=n;i++) ans+=(n-L[i]);
        printf("%lld\n",ans);
    }
    else
    {
        int X;
        for(int i=1;i<=n;i++)
            if(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=d) X=i;
        int r=upper_bound(pos+1,pos+1+n,pos[X-1]+d)-pos-1;
        for(int i=1;i<=r;i++)
        {
            if(i==X-1||i==X) continue;
            int x=lower_bound(pos+1,pos+1+r,pos[i]-d)-pos;
            int y=upper_bound(pos+1,pos+1+r,pos[i]+d)-pos-1;
            L[x]=max(L[x],y);
        }
        for(int i=1;i<=r;i++) L[i]=max(L[i],L[i-1]);
        LL ans=0;
        for(int i=1;i<=r;i++) ans+=(n-L[i]);
        for(int i=1;i<=r;i++) L[i]=0;
        int l=lower_bound(pos+1,pos+1+n,pos[X+1]-d)-pos-1;
        for(int i=l;i<=n;i++)
        {
            if(i==X+1||i==X) continue;
            int x=lower_bound(pos+1,pos+1+r,pos[i]-d)-pos;
            int y=upper_bound(pos+1,pos+1+r,pos[i]+d)-pos-1;
            L[x]=max(L[x],y);
        }
        for(int i=1;i<=n;i++) L[i]=max(L[i],L[i-1]);
        for(int i=l;i<=n;i++) ans+=(n-L[i]);
        printf("%lld\n",ans);
    }
}


inline void solve()
{
    read(n,d);
    for(int i=1;i<=n;i++) read(pos[i]);
    bool flag=true;
    for(int i=3;i<=n;i++) flag&=(pos[i]-pos[i-1]==pos[2]-pos[1]);
    if(flag) return subtaskA();
    // for(int i=1;i<=n;i++) flag|=(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=d);
    // if(flag) return subtaskB();
    for(int i=1;i<=n;i++) L[i]=lower_bound(pos+1,pos+1+n,pos[i]-d)-pos;
    // for(int i=1;i<=n;i++) printf("%d\n",L[i]);
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=0;  g[i]=1;
        for(int j=i+1;j<=n;j++)
        {
            L[j]=max(L[j],i);
            if(L[j]==j) break;
            int minn=f[L[j]],cnt=g[L[j]];
            if(L[j]+1<j&&f[L[j]+1]==minn) cnt+=g[L[j]];
            if(L[j]+2<j&&f[L[j]+2]==minn) cnt+=g[L[j]];
            f[j]=minn+1;
            if(cnt==2) g[j]=2,ans++;
            else if(cnt>2) g[j]=3;
            else g[j]=1;
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int abc,t;  read(abc,t);
    while(t--) solve();
    return 0;
}