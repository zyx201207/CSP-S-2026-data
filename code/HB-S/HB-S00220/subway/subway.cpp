#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
ll c,n,m,d,q;
ll w[N];
vector<ll>pv[N+N],pw[N+N];
ll cnt=0;
ll a[N],t[N];
ll vis[N+N];
ll dis[N+N];
void dijs(ll x,ll y){
    for(int i=1;i<=cnt;i++){
        vis[i]=1000000000000000000;dis[i]=0;
    }
    queue<ll>qx,qd;
    qx.push(x);
    vis[x]=0;
    while(!qx.empty()){
        ll X=qx.front();qx.pop();
        if(c>8&&dis[X]>=2*pv[X].size())continue;
        dis[X]++;
        for(int i=0;i<pv[X].size();i++){
            ll v=pv[X][i];
            if(vis[v]>vis[X]+pw[X][i]){
                vis[v]=vis[X]+pw[X][i];
                qx.push(v),qd.push(vis[v]);
            }
        }
    }
    cout<</*"ans::::::::::::::::"<<*/vis[y]+w[x]+w[y]<<endl;
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    cnt=m;
    for(int i=1;i<=n;i++){
        ll k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            scanf("%lld %lld",&a[j],&t[j]);
            cnt++;
            pv[cnt].push_back(a[j]);pw[cnt].push_back(t[j]);
            pv[a[j]].push_back(cnt);pw[a[j]].push_back(t[j]);
            if(j>1){
                pv[cnt-1].push_back(cnt);pw[cnt-1].push_back(0);
                pv[cnt].push_back(cnt-1);pw[cnt].push_back(0);
            }
        }
    }
    while(q--){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        dijs(x,y);
    }
    return 0;
}
