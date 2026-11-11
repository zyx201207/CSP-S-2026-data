#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dnt=1;
ll fir[2000005];
ll nxt[2000005],to[2000005],we[2000005],w[500005],dp[500005];
ll c,n,m,d,q,a[500005],t[500005],kk[505];
void bpus(ll u,ll v,ll ww){
    nxt[++dnt]=fir[u];
    fir[u]=dnt;
    to[dnt]=v;
    we[dnt]=ww;
    return ;
}struct di{
    ll vv,ww;
};
struct cmop{

    bool operator()(di& x,di& y){
        return x.ww>y.ww;
    };
};

ll dij(ll u,ll v){
    priority_queue<di,vector<di>,cmop> ruq;
    for(ll i=1;i<=m+n;i++){
        dp[i]=0;
    }dp[u]=0;
    di fei;
    fei.vv=u;
    fei.ww=0;
    ruq.push(fei);
    while(!ruq.empty()){
        di luq=ruq.top();
        ruq.pop();
        if(dp[luq.vv]){
            continue;
        }dp[luq.vv]=luq.ww;
        if(luq.vv==v){
            break;
        }
        for(ll i=fir[luq.vv];i;i=nxt[i]){
            ll vr=to[i];
            if(!dp[vr]){
                di uii;
                uii.ww=luq.ww+we[i];
                uii.vv=vr;
                ruq.push(uii);
            }
        }
    }return dp[v];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
        scanf("%lld",&w[i]);
	}
    for(ll i=1;i<=n;i++){
        scanf("%lld",&kk[i]);
        for(ll j=1;j<=kk[i];j++){
            scanf("%lld",&a[j]);scanf("%lld",&t[j]);
            bpus(a[j],m+i,t[j]);bpus(m+i,a[j],t[j]);
        }
    }for(ll i=1;i<=q;i++){
        ll ui,vi;
        scanf("%lld%lld",&ui,&vi);
        printf("%lld\n",w[ui]+dij(ui,vi)+w[vi]);
    }
	return 0;
}
