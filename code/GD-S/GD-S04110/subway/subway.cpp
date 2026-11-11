#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q;
const int N = 505, M = 5e5 + 5, MAX = 1e18;
int w[M], ans[N][N];
struct Sta{
	int s, t;
};
vector<Sta> sta[M];


signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0; i <= 500; i++){
		for(int j = 0; j <= 500; j++){
			if(i == j) ans[i][j] = 0;
			ans[i][j] = MAX;
		}
	}
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		for(int j = 1, x, y; j <= k; j++){
			cin >> x >> y;
			sta[x].push_back({i, y});
		}
	}
	for(int k = 1; k <= m; k++){
		for(auto i : sta[k]){
			for(auto j : sta[k]){
				if(i.s == j.s) ans[i.s][i.s] = 0;
				else ans[i.s][j.s] = ans[j.s][i.s] = min(ans[i.s][j.s], i.t + j.t);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(k == i || i == j || k == j) continue;
				ans[i][j] = ans[j][i] = min(ans[i][j], ans[i][k] + ans[k][j]);
			}
		}
	}
	while(q--){
		int l, r, cnt = MAX;
		cin >> l >> r;
		for(auto i : sta[l])
			for(auto j : sta[r]){
				cnt = min(cnt, w[l] + w[r] + i.t + j.t + ans[i.s][j.s]);
			}
		cout << cnt << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
