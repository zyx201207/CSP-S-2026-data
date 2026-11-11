#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a,b,c,d) for(ll (a)=(b);(a)<=(c);(a)+=(d))
#define per(a,b,c,d) for(ll (a)=(b);(a)>=(c);(a)-=(d))
#define endl '\n'
#define pii pair<ll,ll>
#define _1 first
#define _2 second

ll f[510][510];
ll c,n,m,d,q;
ll w[500010];
ll k[510];
vector<pii> s2l[500010];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m,1) cin>>w[i];
    rep(i,1,n,1) {
        cin>>k[i];
        rep(j,1,k[i],1) {
            ll a1,t1;
            cin>>a1>>t1;
            s2l[a1].push_back({i,t1});
        }
    }
    rep(i,1,n,1) {
        rep(j,1,n,1) {
            if(i==j) continue;
            f[i][j]=1ll*INT_MAX*SHRT_MAX;
        }
    }
    rep(i,1,m,1) {
        rep(j,0,s2l[i].size()-1,1) {
            rep(k,j+1,s2l[i].size()-1,1) {
                ll u=s2l[i][j]._1;
                ll v=s2l[i][k]._1;
                f[u][v]=f[v][u]=min(f[v][u],s2l[i][j]._2+s2l[i][k]._2);
            }
        }
    }
    rep(i,1,n,1) {
        rep(k,1,n,1) {
            rep(j,1,n,1) {
                f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
            }
        }
    }
    while(q--) {
        ll s,t;
        cin>>s>>t;
        ll ans=LLONG_MAX;
        rep(i,0,s2l[s].size()-1,1) {
            rep(j,0,s2l[t].size()-1,1) {
                ans=min(ans,f[s2l[s][i]._1][s2l[t][j]._1]+s2l[s][i]._2+s2l[t][j]._2);
            }
        }
        cout<<ans+w[s]+w[t]<<endl;
    }
    return 0; 
}