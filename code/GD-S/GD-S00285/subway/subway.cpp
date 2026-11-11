#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5+5;
const ll inf=1e18;
int rd(){
    int f=1,s=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) s=s*10+(c^48);
    return f*s;
}
int c,n,m,d,q;
int ww[M];
int hd[M],nxt[2*M],to[2*M],val[2*M],tot;
ll dis[N][N];
int stkv[22],stkw[22],tp;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
    for(int i=1;i<=m;i++) ww[i]=rd();
    for(int i=1;i<=n;i++){
        int _k=rd();
        while(_k--){
            int v=rd(),w=rd();
            nxt[++tot]=hd[v],to[tot]=i,val[tot]=w,hd[v]=tot;
        }
    }

    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) if(j!=i) dis[i][j]=inf;
    
    for(int i=1;i<=m;i++){
        tp=0;
        for(int j=hd[i];j;j=nxt[j]){
            for(int k=1;k<=tp;k++)
                if(stkw[k]+val[j]<dis[stkv[k]][to[j]])
                    dis[stkv[k]][to[j]]=dis[to[j]][stkv[k]]=stkw[k]+val[j];
            stkv[++tp]=to[j],stkw[tp]=val[j];
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(dis[j][i]+dis[i][k]<dis[j][k])
                    dis[j][k]=dis[j][i]+dis[i][k];
    
    while(q--){
        int x=rd(),y=rd();
        ll ans=inf;
        tp=0;
        for(int i=hd[x];i;i=nxt[i])
            stkv[++tp]=to[i],stkw[tp]=val[i];

        for(int i=hd[y];i;i=nxt[i])
            for(int j=1;j<=tp;j++)
                ans=min(ans,stkw[j]+val[i]+dis[stkv[j]][to[i]]);
                
        ans+=ww[x]+ww[y];
        cout<<ans<<'\n';
    }
    return 0;
}
