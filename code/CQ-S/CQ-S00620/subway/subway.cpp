#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int rd(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
    return x*f;
}
const int N=505,M=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
int cid,n,m,d,q,at,w[M],head[M],dis[N][N];
struct node{int to,nt,val;}a[M];
void Min(int &x,int y){
    (x>y)&&(x=y);
}
void add(int u,int x,int t){
    for(int i=head[u];i;i=a[i].nt){
        int y=a[i].to,_t=a[i].val;
        Min(dis[x][y],t+_t);
        Min(dis[y][x],t+_t);
    }
    a[++at]={x,head[u],t};head[u]=at;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cid=rd(),n=rd(),m=rd(),d=rd(),q=rd();
    for(int i=1;i<=m;i++)w[i]=rd();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=INF;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        int k=rd();
        for(int j=1;j<=k;j++){
            int u=rd(),t=rd();
            add(u,i,t);
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)Min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x=rd(),y=rd(),ans=INF;
        if(x==y){puts("0");continue;}
        for(int i=head[x];i;i=a[i].nt)for(int j=head[y];j;j=a[j].nt){
            Min(ans,a[i].val+a[j].val+dis[a[i].to][a[j].to]);
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}