#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define test(x) freopen(x".in","r",stdin)
#define LL long long
#define db double
#define i128 __int128
#define lb(x) (x&-x)
#define fir first
#define sec second
const int N=505,M=5e5+5,inf=1e9;const LL INF=1e18;
int c,n,m,d,q,w[M];LL dis[N][N];vector<pair<int,int>> v[M];
char ch;LL tmp;
LL read(){
    tmp=0,ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch>='0'&&ch<='9') tmp=tmp*10+ch-'0',ch=getchar();
    return tmp;
}
void solve(){
    n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1,cnt,x,t;i<=n;i++){
        cnt=read();
        for(int j=1;j<=cnt;j++) x=read(),t=read(),v[x].emplace_back(i,t);
    }
    for(int i=1;i<=n;i++) fill(dis[i]+1,dis[i]+1+n,INF),dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int x,y,z,j=0;j<v[i].size()-1;j++)
            for(int k=j+1;k<v[i].size();k++)
                x=v[i][j].fir,y=v[i][k].fir,z=v[i][j].sec+v[i][k].sec,
                dis[x][y]=dis[y][x]=min(dis[x][y],(LL)z);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(i!=k&&dis[i][k]<INF)
                for(int j=i+1;j<=n;j++)
                    if(j!=k&&j!=i&&dis[k][j]<INF)
                        dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1,x,y;i<=q;i++){
        LL ans=INF;scanf("%d%d",&x,&y);
        for(pair<int,int> p1:v[x])
            for(pair<int,int> p2:v[y])
                ans=min(ans,dis[p1.fir][p2.fir]+p1.sec+p2.sec+w[x]+w[y]);
        printf("%lld\n",ans);
    }
}
int main(){
    FILE("subway");
    int T=1;scanf("%d",&c);
    while(T--) solve();
    return 0;
}
/*
赛百味，拼了！

我爱上拼了的 Subway love ——《肉爱》
*/