#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e6 + 5;

int C, T, n; ll d;
int lst[MAXN], nxt[MAXN], dis[MAXN], cnt[MAXN];
int R[MAXN], s[MAXN];
ll x[MAXN];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> C >> T; 
	while (T--){
		cin >> n >> d;
		for (int i=1; i<=n; i++) cin >> x[i];
		if (n == 1){ cout << "0\n"; continue; }
		if (C <= 10){
			for (int i=1; i<=n; i++){
				int l = 1, r = i, res = 0;
				while (l <= r){
					int mid = (l + r) / 2;
					if (x[i] - x[mid] <= d) res = mid, r = mid - 1;
					else l = mid + 1;
				} lst[i] = res;
			}
			ll ans = 0;
			for (int i=1; i<=n; i++){
				dis[i] = 0, cnt[i] = 1, s[i - 1] = 0, s[i] = 1;
				R[i] = i; int ls = i, rs = i;
				for (int j=i+1; j<=n; j++) s[j] = R[j] = dis[j] = cnt[j] = 0;
				for (int j=i+1; j<=n; j++){
					if (lst[j] == j) break;
					int p = max(i, lst[j]);
					int l = p, r = (R[p] ? R[p] : rs);
					dis[j] = dis[p] + 1;
					cnt[j] = min(s[r] - s[l - 1], 3);
					ans += (cnt[j] == 2);
					s[j] = s[j - 1] + cnt[j];
					if (dis[j] == dis[j - 1]){ rs = j; continue; }
					for (int k=ls; k<=rs; k++) R[k] = rs;
					ls = rs = j;
				}
			}
			cout << ans << "\n";	
			continue;
		}
		if (C <= 12){
			ll t = x[2] - x[1], ans = 0;
			ll k = min(d / t, (ll)n - 1);
			if (k <= 1){ cout << 0 << "\n"; continue; }
			for (int i=1; i<=n; i++){
				if (i + k >= n) continue;
				ans += (i + k + k - 1 <= n);
			}
			cout << ans << "\n";
			continue;
		}
		if (C <= 14){
			ll ans = 0;
			for (int i=1; i<=n; i++){
				int l = i, r = n, res = 0;
				while (l <= r){
					int mid = (l + r) / 2;
					if (x[mid] - x[i] <= d) res = mid, l = mid + 1;
					else r = mid - 1;
				} nxt[i] = res;
			}
			for (int i=1; i<=n; i++){
				if (nxt[i] >= n) continue;
				if (nxt[i] <= i + 1) continue;
				int p = nxt[i], q = nxt[p], q_ = nxt[p - 1], q__ = (p - 2 > i ? nxt[p - 2] : i - 1);
				if (p == q) continue;
				int l = max(q__ + 1, p + 1), r = q_;
				if (l > r) continue; ans += (r - l + 1);
			}
			cout << ans << "\n";
			continue;
		}
	}
	return 0;
}