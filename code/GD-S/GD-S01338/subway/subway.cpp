#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm = 5e5 + 9, maxn = 509;
const ll llmax = 1e18;
int a[maxm];
struct node{
	int pos, w;
};
vector<node> vec[maxn], du[maxm];
ll dis[maxn][maxn];
int cnt[maxm];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
//	clock_t st = clock();
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		while(k--){
			int pos, w;
			cin >> pos >> w;
			du[pos].push_back({i, w});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	for(int i = 1;i <= m;i++){
		for(auto l : du[i]){
			for(auto r : du[i]){
				if(l.pos == r.pos) continue;
				dis[l.pos][r.pos] = min(dis[l.pos][r.pos], (ll)l.w + r.w);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	} 
	while(q--){
		int u, v;
		cin >> u >> v;
		ll ans = llmax;
		for(auto l : du[u]){
			for(auto r : du[v]){
				ans = min(ans, dis[l.pos][r.pos] + l.w + r.w + a[u] + a[v]);
			} 
		}
		cout << ans << "\n";
	}
//	clock_t ed = clock();
//	cout << (double)(ed - st) / CLOCKS_PER_SEC * 1000;
	return 0;
}

