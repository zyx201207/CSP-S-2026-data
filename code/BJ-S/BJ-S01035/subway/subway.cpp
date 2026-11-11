#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,w[N],a[505][N],c,d,q,t[505][N],k,x,y,hd[N],cnt,v[N];
long long ans=1e9;
struct tree{
    long long nxt,to,fr,lx;
}e[N*2];
void add(long long x,long long y,long long z){
    e[++cnt].nxt=hd[x];
    e[cnt].to=y;
    e[cnt].fr=x;
    e[cnt].lx=z;
    hd[x]=cnt;
}
void dfs(long long xx,long long yy,long long sum,long long sl,long long xl){
    if(e[xx].fr==yy){
        ans=min(sum,ans);
        return;
    }
    for(long long i=hd[xx];;i=e[i].nxt){
        if(sl==e[i].lx||(sl==0&&xl==0)&&v[i]==0){
            sl=e[i].lx;
            xl=i;
            v[i]=1;
            dfs(e[i].to,yy,sum,e[i].lx,xl);
            v[i]=0;
        }else{
            long long sll=sl,xll=xl;
            sl=e[i].lx;
            xl=i;
            v[i]=1;
            dfs(e[i].to,yy,sum+t[sll][e[xll].to]+t[sl][e[xl].fr],e[i].lx,xl);
            v[i]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&k);
        for(long long j=1;j<=k;j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            if(j!=1){
                add(a[i][j],a[i][j-1],i);
                add(a[i][j-1],a[i][j],i);
            }
        }
    }
    for(long long i=1;i<=q;i++){
        scanf("%lld%lld",&x,&y);
        dfs(x,y,w[x]+w[y],0,0);
        cout<<ans<<endl;
        ans=1e9;
    }
    return 0;
}
