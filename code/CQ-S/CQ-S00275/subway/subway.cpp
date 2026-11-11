#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=505,MAXM=5e5+5,MAXD=25;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k[MAXN];
ll w[MAXM],f[MAXN][MAXN];
vector<int> state[MAXM];
unordered_map<int,ll> mp[MAXN];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
    #endif
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            int a,t;
            scanf("%d%d",&a,&t);
            state[a].push_back(i);
            mp[i][a]=t;
        }
    }
    memset(f,INF,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j:state[i])
            for(int k:state[i]) f[j][k]=min(f[j][k],mp[j][i]+mp[k][i]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int r=1;r<=q;r++){
        int xr,yr;
        ll ans=INF;
        scanf("%d%d",&xr,&yr);
        for(int i:state[xr])
            for(int j:state[yr]) ans=min(ans,w[xr]+w[yr]+mp[i][xr]+mp[j][yr]+f[i][j]);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
多源最短路吗？坏了我好像不会。
坏了 n=500 真是多源最短路。
让我现场研发一下 Floyd。
我记得好像是一个三维的数组 f[k][i][j]，然后滚动第一维。
好像是表示从 i 到 j 经过 k 的最短路。是这样吗？
但是你要从 k-1 转移过来啊。让我想想。
我认为去年发退役感言的 kunkunge 应该做今年这套题。
f[i][j]=min(f[i][k],f[k][j]) 是这样吧？我画个图。
诶不对 n 是地铁，m 才是地铁口。坏了，那这是什么滚木。
也不是最小生成树啊，它求的是边权和。
唉青鱼轨道还是玩的太少了。我怎么不会做 /jk
Floyd 好像不能优化吧。还是说我写错了？哦不不我无疑是愤怒的。
先看 T3。
滚回来看 T2，突然想到既然站与站不行我还能算地铁与地铁之间啊。
那么时间复杂度就是 O(md^2+n^3+qd^2) 的，太棒了刚好哈哈哈。
不对空间好像不太够，O(md) 的话就是 1e8 个 int 了。
我服了这道题怎么这么难绷啊 /kk
哦不是 O(md)，它就是 O(m)，OK。
CCF 卡不卡输入啊，不是很想写快读。
话说回来 memset(INF) 和 memset(0x3f) 应该没区别吧。。。
*/