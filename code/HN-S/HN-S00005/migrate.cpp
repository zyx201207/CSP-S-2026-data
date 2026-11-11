#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 5;

int n, c_, nxt[N], s, t, cnt, Cnt;
ll d, x[N], ans;

void dfs(int now, int step){
	if(Cnt > 2 || step > cnt || (step == cnt && now != t)){
		return;
	}
	if(now == t){
		Cnt++;
		return;
	}
	for(int j = now + 1; j <= min(t, nxt[now]); j++){
		dfs(j, step + 1);
		if(Cnt > 2){
			return;
		}
	}
	return;
}

void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++){
		int l = i, r = n, ans = i;
		while(l <= r){
			int mid = (l + r) / 2;
			if(x[mid] - x[i] <= d){
				ans = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		nxt[i] = ans;
	}
	if(n <= 2){
		cout << "0\n";
		return;
	}
	if(c_ == 11 || c_ == 12){
		if(nxt[1] <= 2 || nxt[1] == n){
			cout << "0\n";
			return;
		}
		if(nxt[1] * 2 - 1 <= n) cout << n - nxt[1] * 2 + 3 << '\n';
		else cout << "0\n";
		return;
	}
	ans = 0;
	for(int i = 1; i < n; i++){
		for(int j = i + 3; j <= n; j++){
			s = i, t = j;
			Cnt = 0, cnt = 0;
			int rt = i;
			while(1){
				if(nxt[rt] == rt){
					Cnt = 3;
					break;
				}
				rt = nxt[rt];
				cnt++;
				if(rt >= j){
					break;
				}
			}
			dfs(i, 0);
			ans += (Cnt == 2);
		}
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> c_ >> T;
	while(T--){
		solve();
	}
	return 0;
}
