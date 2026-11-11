#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,t;
	cin >> c >> t;
	while(t--){
		ll n,d;
		cin >> n >> d;
		vector<ll> x(n+1);
		for(int i=1;i<=n;i++) cin >> x[i];
		vector<vector<int>> g(n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			queue<pair<int,int>> q;
			vector<ll> dis(n+1,2e18+1ll),ls(n+1);
			dis[i]=0;
			ls[i]=1;
			q.push({i,0});
			while(!q.empty()){
				int u=q.front().first,fa=q.front().second;
				q.pop();
				for(int v:g[u]){
					if(v==fa) continue;
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						ls[v]=1;
						q.push({v,u});
					}else if(dis[v]==dis[u]+1){
						ls[v]++;
						q.push({v,u});
					}
				}
			}for(int j=i+1;j<=n;j++) if(ls[j]==2) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
