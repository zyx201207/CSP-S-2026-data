#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N  = 2e6+10;
ll n,d,a[N],f[N],viss[N];
ll ans;
bool vis[N];
vector<int> g[N];
void bfs(int s){
	queue<int> q;
	vis[s] = 1;
	f[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v:g[u]){
			if(vis[v]){
				if(f[v]==f[u]+1)viss[v]++;
			}else{
				vis[v] = 1;
				f[v] = f[u]+1;
				q.push(v);
			}
		}
	}
}
void solve(){
	ans = 0;
	cin >> n >> d;
	for(ll i=1;i<=n;i++)
		cin >> a[i];
	for(ll i=1;i<=n;i++){
		vector<int>().swap(g[i]);
		for(ll j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				g[i].push_back(j);
			}
			else break;
		}
	}
	for(ll i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(viss,0,sizeof(viss));
		memset(f,0,sizeof(f));
		bfs(i);
		for(ll j=1;j<=n;j++){
			if(viss[j]==1)ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll T,C;
	cin >> C >> T;
	while(T--)solve();
	return 0;
}
//纷乱的光线里，我闭上眼去看
