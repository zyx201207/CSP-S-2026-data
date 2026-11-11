#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q,w[N],k[N],a[N][M],t[N][M],hc[N];
bool edge[N][N];
bool vis[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++) scanf("%lld %lld",&a[i][j],&t[i][j]);
    }
    bool flag=true;
    int T=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(t[i][j]!=t[1][1]) flag=false;
        }
    }
    if(flag){
        T=t[1][1];
        for(int i=1;i<=n;i++){
            for(int u=1;u<k[i];u++){
                for(int v=u+1;v<=k[i];v++){
                    edge[u][v]=1;
                    edge[v][u]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                hc[a[i][j]]++;
            }
        }
        for(int k=1;k<=q;k++){
            int s,e,ans=0;
            scanf("%lld %lld",&s,&e);
            memset(vis,false,sizeof vis);
            vis[s]=true;
            queue<int> q;
            q.push(s);
            int cnt=0;
            while(!q.empty()){
                int x=q.front();
                for(int i=1;i<=n;i++){
                    if(edge[x][i]==1 && !vis[x]){
                        q.push(x);
                        cnt+=1LL*hc[x]*T;
                        if(x==e) ans=max(ans,cnt);
                    }
                }
            }
            ans+=(w[s]+w[e]);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
