#include <bits/stdc++.h>
using namespace std;
const int N = 2000005, inf = 0x3f3f3f3f;
int c, T, n, dis[N], cnt[N], an[N], tp;
long long d, x[N];
int cha(){
	long long ch = x[2] - x[1];
	for (int i = 3; i <= n; ++i){
		if(x[i] - x[i - 1] != ch){
			return 0;
		}
	}
	return 1;
}
void solve(){
	long long ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	if ((11 <= c && c <= 12) || cha()){
		for (int j = 2; j <= n; ++j){
			cnt[j] = 0;
		}
		dis[1] = 0;
		cnt[1] = 1;
		tp = 0;
		for (int l = 1, r = 2; r <= n; ++r){
			while(x[r] - x[l] > d){
				++l;
			}
			if (l == r){
				break;
			}
			dis[r] = dis[l] + 1;
			for (int i = l; i < r; ++i){
				if (dis[i] + 1 != dis[r]){
					break;
				}
				cnt[r] += cnt[i];
				if (cnt[r] > 2){
					break;
				}
			}
			if (cnt[r] == 2){
				an[++tp] = r;
			}
		}
		for (int i = 1; i <= n; ++i){
			ans += upper_bound(an + 1, an + tp + 1, n - i + 1) - an - 1;
		}
		cout << ans << "\n";
		return;
	}
	for (int u = 1; u < n; ++u){
		for (int j = u + 1; j <= n; ++j){
			cnt[j] = 0;
		}
		dis[u] = 0;
		cnt[u] = 1;
		for (int l = u, r = u + 1; r <= n; ++r){
			while(x[r] - x[l] > d){
				++l;
			}
			if (l == r){
				break;
			}
			dis[r] = dis[l] + 1;
			for (int i = l; i < r; ++i){
				if (dis[i] + 1 != dis[r]){
					break;
				}
				cnt[r] += cnt[i];
				if (cnt[r] > 2){
					break;
				}
			}
			if (cnt[r] == 2){
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--){
		solve();
	} 
	return 0;
}

