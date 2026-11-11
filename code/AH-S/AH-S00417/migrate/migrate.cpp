#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int ysz, ttt, n;

namespace sub1{
	const int N = 305;
	int L[N], R[N], p[N], tot;
	ll D, a[N];

	bool check(int l, int r){
		int now = l;
		tot = 0;
		while(now <= r){
			p[++tot] = now;
			now = R[now];
		}
		if(p[tot] != r) p[++tot] = r;
		if(tot <= 2) return 0;
		int cnt = 0;
		for(int i = 1; i <= tot - 2; i++){
			if(R[p[i]] == L[p[i + 2]] + 1) cnt++;
			else if(R[p[i]] != L[p[i + 2]]) return 0;
		}
		return cnt == 1;
	}
	void work(){
		while(ttt--){
			cin >> n >> D;
			for(int i = 1; i <= n; i++) cin >> a[i];
			for(int i = 1; i <= n; i++){
				int l = 1, r = i - 1, mid, res = 0;
				while(l <= r){
					mid = ((r - l) >> 1) + l;
					if(a[i] - a[mid] <= D) res = mid, r = mid - 1;
					else l = mid + 1;
				}
				L[i] = res;
				l = i + 1, r = n, res = n + 1;
				while(l <= r){
					mid = ((r - l) >> 1) + l;
					if(a[mid] - a[i] <= D) res = mid, l = mid + 1;
					else r = mid - 1;
				}
				R[i] = res;
			}
			int ans = 0;
			for(int i = 1; i <= n - 2; i++){
				for(int j = i + 2; j <= n; j++){
					if(check(i, j)) ans++;
				}
			}
			cout << ans << '\n';
			for(int i = 1; i <= n; i++) L[i] = R[i] = a[i] = 0;
		}
	}
}
namespace sub2{
	const int N = 5e3 + 5;
	int L[N], R[N];
	ll D, a[N];

	void work(){
		while(ttt--){
			cin >> n >> D;
			for(int i = 1; i <= n; i++) cin >> a[i];
			for(int i = 1; i <= n; i++){
				int l = 1, r = i - 1, mid, res = 0;
				while(l <= r){
					mid = ((r - l) >> 1) + l;
					if(a[i] - a[mid] <= D) res = mid, r = mid - 1;
					else l = mid + 1;
				}
				L[i] = res;
				l = i + 1, r = n, res = n + 1;
				while(l <= r){
					mid = ((r - l) >> 1) + l;
					if(a[mid] - a[i] <= D) res = mid, l = mid + 1;
					else r = mid - 1;
				}
				R[i] = res;
			}
			// for(int i = 1; i <= n; i++) cout << L[i] << ' ';
			// cout << '\n';
			// for(int i = 1; i <= n; i++) cout << R[i] << ' ';
			// cout << '\n';
			ll ans = 0;
			for(int i = 1; i <= n; i++){
				int now = R[i];
				bool flag = 0;
				while(R[now] <= n && !flag){
					for(int i = now + 1; i <= R[now]; i++)
						if(L[i] == now - 1) ans++;
					if(L[R[now]] == now) now = R[now];
					else if(L[R[now]] == now - 1) flag = 1;
					else break;
				}
				// cout << "shit: " << i << '\n';
				if(!flag) continue;
				// cout << "shit: " << i << ' ' << now << '\n';
				// now: p_{i + 1}
				// cout << ans << ' ';
				now = R[now];
				// cout << now << '\n';
				// cout << ans << ' ';
				while(R[now] <= n){
					for(int i = now + 1; i <= R[now]; i++)
						if(L[i] == now) ans++;
					if(L[R[now]] == now) now = R[now];
					else break;
				}
				// cout << ans << '\n';
			}
			cout << ans << '\n';
			for(int i = 1; i <= n; i++) L[i] = R[i] = a[i] = 0;
		}
	}
}

int main(){

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> ysz >> ttt;
	if(ysz <= 6) sub1::work();
	else if(ysz <= 10) sub2::work();

	return 0;
}