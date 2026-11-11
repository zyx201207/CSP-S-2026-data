#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=520;
const int M=5e5+10;
const int T=22;
const LL inf=1e18;

LL dis[N][N];
int a[M][T],t[M][T],len[M],w[M];

void read() {}
template <typename T,typename ...Args>
void read(T &x,Args &...args)
{
    x=0;  char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    read(args...);
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int abc,n,m,d,q,x,y,z;
    read(abc,n,m,d,q);
    for(int i=1;i<=m;i++) read(w[i]);
    for(int i=1;i<=n;i++)
    {
        read(z);
        for(int j=1;j<=z;j++)
        {
            read(x,y);
            a[x][++len[x]]=i;
            t[x][len[x]]=y;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=inf;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=len[i];j++)
            for(int k=1;k<=len[i];k++) dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],(LL)t[i][j]+t[i][k]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=q;i++)
    {
        read(x,y);  LL ans=inf;
        for(int i=1;i<=len[x];i++)
            for(int j=1;j<=len[y];j++)
                ans=min(ans,t[x][i]+t[y][j]+dis[a[x][i]][a[y][j]]);
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}