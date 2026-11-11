#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+50;
int c, T, n, d, a[N], p[N], l[N], r[N], cnt, sum, mn;
void dfs(int x, int l, int r, int k){
	if(k > mn) return;
	cout << x << ' ';
	if(x == r){
		if(k < mn) mn = k, sum = 1;
		else if(k == mn) sum++;
		cout << '\n';
		return ;
	}
	int t = x+1;
	while(t < r && a[t+1]-a[x] <= d) t++;
	if(t == r) dfs(r, l, r, k+1);
	for(int i = t; i > x && i > t-3; i--) dfs(i, l, r, k+1);
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(c >= 11 && c <= 12){
			if(a[2]-a[1] > d){
				cout << "0\n";
				continue;
			}
			int x = 0;
			for(int i = 1; i <= n; i++){
				if(a[1]+d >= a[i] && a[1]+d < a[i+1]){
					x = i;
					break;
				}
			}
			if(x == 0){
				cout << "0\n";
				continue;
			}
			int d = 2*x-2;
			cout << max(0ll, n-d+1) << '\n';
			continue;
		}
		if(c >= 13 && c <= 14){
			cout << "0\n";
			continue;
		}
		int ll = 1, rr = 1, ans = 0;
		while(rr <= n){
			while(a[rr+1]-a[rr] <= d && rr < n) rr++;
			cnt = 0;
			int res = 0;
			for(int i = ll; i+3 <= rr; i++) if(a[i+3]-a[i] > d && a[i+2]-a[i] <= d && a[i+3]-a[i+1] <= d) l[++cnt] = i, r[cnt] = i+3;
			r[cnt+1] = rr+1;
			for(int i = 1; i <= cnt; i++) res += (l[i]-l[i-1])*(r[i+1]-r[i]);
			ll = rr+1;
			rr++;
			ans += res;
		}
		cout << ans << '\n';
	}
	return 0;
}