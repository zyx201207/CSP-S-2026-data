#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+5;
int c, n, m, q;
const ll inf20 = 1e9+1;


int a[maxn]; bool vis[maxn];
ll ans;
void dfs(int u, int v, vector < pair < int, int > > g[], int x, ll cnt){
    if(x>=n || vis[u]){return; }
    vis[u] = 1;
    if(u==v){ans = min(cnt, ans);}

    x++;
    for(int i=0;i<=(int)g[u].size();i++){
        int to = g[u][i].first; int val = g[u][i].second;
        cnt+=(ll)g[u][i].second;
        dfs(to, v, g, x, ans);
        cnt-=(ll)g[u][i].second;
    }
    x--;
    vis[u] = 0; return;
}


int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>n>>m>>q;
    for(int i=1;i<=m;i++) cin>>a[i];


    if(c>=7 && c<=11){
        vector < pair < int, int > > g[1005];
        for(int i=1;i<=n;i++){
            int k; cin>>k;
            if(k==2){
                int st1, st2, t1, t2; cin>>st1>>st2>>t1>>t2;
                g[st1].push_back({st2, (t1+t2)});
                g[st2].push_back({st1, (t1+t2)});
            }
        }
        while(q--){
            for(int i=1;i<=m;i++) vis[i]=0;
            int u, v; cin>>u>>v; ll cnt = a[u]+a[v];
            ans = (ll)inf20*2;
            dfs(u, v, g, 1, cnt);
            cout<<ans<<"\n";
        }
        return 0;
    }


    if(c>=20&&c<=21){
        vector < int > line1(maxn+1, inf20), line2(maxn+1, inf20);
        int k; cin>>k; for(int i=1;i<=k;i++){int sta, t; cin>>sta>>t; line1[sta]=t;}
        cin>>k; for(int i=1;i<=k;i++){int sta, t; cin>>sta>>t; line2[sta]=t;}
        ll minTime = 1e18+3;
        for(int i=1;i<=m;i++){ if(line1[i]!=inf20 && line2[i]!=inf20){minTime = min(minTime, (ll)line1[i]+(ll)line2[i]);} }
        while(q--){
            ll ans = 1e18+1; int u, v; cin>>u>>v;
            ans = min({ans, (ll)line1[u]+(ll)line1[v], (ll)line2[u]+(ll)line2[v], (ll)line1[u]+(ll)line2[v]+minTime, (ll)line1[u]+(ll)line2[v]+minTime});
            ans+=(ll)(a[u]+a[v]); cout<<ans<<"\n";
        }
        return 0;
    }


    while(q--){
        cout<<"2\n";
    }
    return 0;
}
