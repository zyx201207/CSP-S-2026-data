#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;


int low(int x){
	return x & -x;
}

int n, m;
int a[N], ki[N];

vector <int> b[35];
int cnt[35];
bool del[N];

int ans = 0;
void dfs(int step, int ad, int cnt){
	if(cnt > m) return;
	if(step > n){
		if(cnt < m) return;
		ans = max(ans, ad);
		return;
	}
	dfs(step + 1, ad & a[step], cnt + 1);
	dfs(step + 1, ad, cnt);
}

int cost(int i){
	int x = a[i];
	int res = 0;
	while(x > 0){
		int k = __lg(low(x));
		if(cnt[k] == m) res += (1ll << k);
		x -= low(x);
	}
	return res;
}

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	bool flag = true;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		int x = a[i];
		if(a[i] != (1ll << __builtin_popcount(a[i])) - 1){
			flag = false;
		}
		while(x > 0){
			int k = __lg(low(x));
			b[k].push_back(i);
			cnt[k] ++;
			x -= low(x);
		}
	}
	if(n <= 20){
		ans = 0;
		dfs(1, INT_MAX, 0);
		cout << ans;
		return 0;
	}
	if(m == 1){
		ans = 0;
		for(int i = 1; i<= n; i ++){
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		ans = 0;
		for(int i = 1; i<= n; i ++){
			for(int j = i + 1; j<=n; j ++){
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n){
		ans = INT_MAX;
		for(int i = 1; i<= n; i ++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == n - 1){
		vector <pair <int, int>> v;
		for(int i = 1; i <= n; i ++){
			v.push_back({cost(i), i});
		}
		sort(v.begin(), v.end());
		del[v.front().second] = true;
		ans = INT_MAX;
		for(int i = 1; i <= n; i ++){
			if(del[i]) continue;
			ans &= a[i];
		}
		cout << ans;
	}
	if(flag){
		ans = 0;
		for(int i = 0; i<= 30; i ++){
			if(cnt[i] >= m) ans += (1ll << i);
		}
		cout << ans;
		return 0;
	}
	int st = -1;
	for(int i = 30; i >= 0; i --){
		if(cnt[i] < m) continue;
		st = i;
		break;
	}
	if(b[st].size() == m){
		ans = INT_MAX;
		for(auto i : b[st]){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	int tot = 0;
	for(int i = st; i >= 0; i --){
		if(tot == n - m) break;
		vector <pair <int, int>> v;
		for(auto j : b[i]){
			if(del[j]) continue;
			int res = 0;
			int x = a[j];
			while(x > 0){
				int k = __lg(low(x));
				if(cnt[k] == m) res += (1ll << k);
				x -= low(x);
			}
			v.push_back({res, j});
		}
		sort(v.begin(), v.end());
		for(auto j : v){
			if(j.first) break;
			del[j.second] = true;
			tot ++;
			if(tot == n - m) break;
			int x = a[j.second];
			while(x > 0){
				int k = __lg(low(x));
				cnt[k] --;
				x -= low(x);
			}
		}
	}
	if(tot == n - m){
		int ans = INT_MAX;
		for(int i = 1; i <= n; i ++){
			if(del[i]) continue;
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	return 0;
}
