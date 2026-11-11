#include<bits/stdc++.h>
#define fs first
#define sc second
#define int long long
using namespace std;

const int N = 2e6 + 5, inf = 1e9 + 7;

int c, T, n, d, cnt, lim;
int a[N];

int min_dis(int u, int x, int dis){
	if(u == x) return dis;
	if(a[u + 1] - a[u] > d) return inf;
	int pos = u;
	while(a[pos + 1] - a[u] <= d && pos < x) pos++;
	return min_dis(pos, x, dis + 1);
}

void dfs(int u, int x, int dis){
	if(dis == lim){
		if(u == x) cnt++;
		return;
	}
	for(int i = u + 1; i <= x;i++){
		if(a[i] - a[u] > d) break;
		dfs(i, x, dis + 1);
	}
}

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	while(T--){
		
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		
		if(n == 1){
			cout << "0\n";
			continue;
		}
		
		if(c >= 11 && c <= 12){
			int p = a[2] - a[1];
			int k = d / p;
			if(k < 1) cout << "0\n";
			else{
				int res = 0;
				for(int i = 1;i <= n;i++) res += (n - i + 1 - k + 1) / (k + 1);
				cout << res << "\n";
			}
			continue;
		}
		
		int ans = 0;
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				lim = min_dis(i, j, 0);
				if(lim == inf) continue;
				cnt = 0;
				dfs(i, j, 0);
				if(cnt == 2)  ans++;
			}
		}
		cout << ans << "\n";
		
	}
	
	return 0;
	
}
