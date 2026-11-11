#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, d, ans = 0;
vector<ll> x, same, dis;
vector<vector<ll>> g;
void bfs(ll u){
    queue<ll> q;q.push(u);
    dis[u] = 0;
    while(!q.empty()){
        ll u = q.front();q.pop();
        for(ll& v:g[u]){
            
            if(dis[v]!=-1){
                //cout<<u<<' '<<v<<' '<<dis[u]<<' '<<dis[v]<<endl;
                if(dis[v]==dis[u]+1){
                    if(same[v]==1) {
                        ans--;continue;
                    }ans++;same[v] = 1;
                }continue;
            }
            q.push(v);
            dis[v] = dis[u]+1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll c, t;cin>>c>>t;
    while(t--){
        ans = 0;
        cin>>n>>d;
        same.assign(n+1, 0);
        x.assign(n+1, 0);
        g.assign(n+1, vector<ll>());
        for(int i = 1;i<=n;i++){
            cin>>x[i];
            for(int j = i-1;j>=1;j--){
                if(abs(x[i]-x[j])<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        // for(int i = 1;i<g.size();i++){
        //     cout<<i<<' ';
        //     for(int j = 0;j<g[i].size();j++){
        //         cout<<" {"<<g[i][j].v<<' '<<g[i][j].w<<"},";
        //     }cout<<endl;
        // }
        for(int i = 1;i<=n;i++){
            dis.assign(n+1, -1);
            same.assign(n+1, 0);
            bfs(i);
            //cout<<endl;
            // for(int i = 1;i<=n;i++){
            //     cout<<dis[i]<<' ';
            // }cout<<endl;
        }cout<<ans/2<<endl;
    }
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
36pts
*/