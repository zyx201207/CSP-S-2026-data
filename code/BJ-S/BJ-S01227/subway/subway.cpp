#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int M=1e3+10,N=510;
int w[M];
struct S{
    int to,next,len;
}a[M*2];
int pre[M*2],tot;
void add(int x,int y,int len){
    a[++tot]={y,pre[x],len};
    pre[x]=tot;
}
int x[N][M],t[N][M];
typedef pair<int,int> pii;
int ans=0;
void dij(int s,int e){
    priority_queue<pii,vector<pii>,greater<pii> > q;
    int d[M];
    bool f[M];
    memset(d,0x3f,sizeof(d));memset(f,false,sizeof(f));
    q.push({0,s});
    d[s]=0;
    while(!q.empty()){
        pii h=q.top();
        int dis=h.first,p=h.second;
        q.pop();
        if(f[p]) continue;
        f[p]=true;
        for(int i=pre[p];i;i=a[i].next){
            int to=a[i].to;
            if(d[to]>dis+a[i].len){
                d[to]=dis+a[i].len;
                q.push({d[to],to});
            }
        }
    }
    ans+=d[e];
}
int k[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&x[i][j],&t[i][j]);
        }
        for(int l=1;l<=k[i];l++){
            for(int r=l+1;r<=k[i];r++){
                add(x[i][l],x[i][r],t[i][r]);
                add(x[i][r],x[i][l],t[i][l]);
            }
        }
    }
    while(q--){
        int l;
        int r;
        ans=0;
        scanf("%lld%lld",&l,&r);
        bool fff=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(x[i][j]==l){
                    fff=true;
                    ans+=t[i][j];
                    break;
                }
            }
            if(fff) break;
        }
        ans+=w[l]+w[r];
        dij(l,r);
        printf("%lld\n",ans);
    }
    return 0;
}
