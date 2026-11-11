#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
inline ll rd(){
    char ch=getchar();
    ll f=1,x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
const ll N_ = 505,M_=5e5+10,inf=1e12;
ll ans,dis[N_][N_],N,M,Q,D,C,W[M_];
vector<pair<ll,ll> > q[M_];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    C=rd();N=rd();M=rd();D=rd();Q=rd();
    for(int i=1;i<=M;i++)W[i]=rd();
    for(int i=1;i<=N;i++){
        ll K;
        K=rd();
        for(int j=1;j<=K;j++){
            ll A=rd(),T=rd();
            q[A].push_back({i,T});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=M;i++){
        for(auto j:q[i])
            for(auto k:q[i]){
                if(j.fi==k.fi){
                    dis[j.fi][j.fi]=0;
                    continue;
                }
                dis[j.fi][k.fi]=min(dis[j.fi][k.fi],j.se+k.se);
                dis[k.fi][j.fi]=min(dis[k.fi][j.fi],j.se+k.se);
            }
    }
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--){
        ll x=rd(),y=rd();
        ans=inf;
        for(auto a:q[x])
            for(auto b:q[y])
                ans=min(ans,dis[a.fi][b.fi]+a.se+b.se);
        cout<<ans+W[x]+W[y]<<'\n';
    }
    return 0;
}