#include<bits/stdc++.h>
using namespace std;
const long long N=5029,M=2e6+29,INF=1e18+29;
long long w[N],k[M],a[M],t[M];
queue<long long>que;
long long idx=1e6,idxlen=0;
struct Line{
    long long l,r,dis;
}G[M];
void make_line(long long a,long long b,long long v){
    Line X,Y;
    X.l=a,X.r=b,X.dis=v;
    Y.l=a,Y.r=b,Y.dis=v;
    G[++idxlen]=X;
    G[++idxlen]=Y;
    return;
}
long long dis[M];
bool vis[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    srand(time(0));
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++) cin>>w[i];
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(long long j=1;j<=k[i];j++) cin>>a[j]>>t[j];
    }
    while(q--){
        while(!que.empty()) que.pop();
        long long x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+rand()%1000+1<<endl;
    }
    return 0;
}