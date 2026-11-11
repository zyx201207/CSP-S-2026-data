#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M=5e5+5,N=505;
int c,n,m,d,q,w[M],k[N];
vector<int> a[N],t[N];
set<pair<int,int>> in[M];


vector<ll> dp;
vector<bool> vis;
void ask(int now,int y,ll sum) {
    if(vis[now] and dp[now]<=sum) return ;
    if(!vis[now]) {
        vis[now]=true;
        dp[now]=sum;
    }
    else dp[now]=min(dp[now],sum);
    if(now==y) return ;
    for(auto i:in[now]) {
        int id=i.first;
        ll res=sum+i.second;
        for(int j=0;j<k[id];++j) {
            if(a[id][j]==now) continue;
            ask(a[id][j],y,res+t[id][j]);
        }
    }
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i) {
        cin>>k[i];
        a[i].resize(k[i]);
        t[i].resize(k[i]);
        for(int j=0;j<k[i];++j) {
            cin>>a[i][j]>>t[i][j];
            in[a[i][j]].insert({i,t[i][j]});
        }
    }
    vis.resize(m+1);
    dp.resize(m+1);
    while(q--) {
        int x,y;
        cin>>x>>y;
        ll ans=1ll*(w[x]+w[y]);
        for(int i=1;i<=m;++i) {
            vis[i]=false;
            dp[i]=0;
        }
        ask(x,y,0);
        cout<<dp[y]+ans<<"\n";
    }
    return 0;
}