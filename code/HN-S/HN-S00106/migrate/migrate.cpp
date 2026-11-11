#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 7;
int c, T, n, d, x[N], a[N];
vector<int> del[N];

int check(int n){
	for(int i = 1; i <= n; i++) del[i].clear();
	multiset<int> mt; mt.insert(n + 1);
	for(int i = 1; i < n; i++){
		if(x[i + 1] - x[i] > d) continue;
		int L = -1, R = -1;
		if(1 + 1 == 2){
			int l = 1, r = i;
			while(l <= r){
				int mid = l + r >> 1;
				if(x[i + 1] - x[mid] <= d){
					L = mid, r = mid - 1;
				}else l = mid + 1;
			}
		}
		if(1 + 1 == 2){
			int l = i + 1, r = n;
			while(l <= r){
				int mid = l + r >> 1;
				if(x[mid] - x[i] <= d){
					R = mid, l = mid + 1;
				}else r = mid - 1;
			}
		}
		if(x[R] - x[L] > d){
			int LL = -1, RR = -1;
			if(1 + 1 == 2){
				int l = L, r = i;
				while(l <= r){
					int mid = l + r >> 1;
					if(x[R] - x[mid] > d){
						LL = mid, l = mid + 1;
					}else r = mid - 1;
				}
			}
			if(1 + 1 == 2){
				int l = i + 1, r = R;
				while(l <= r){
					int mid = l + r >> 1;
					if(x[mid] - x[L] > d){
						RR = mid, r = mid - 1;
					}else l = mid + 1;
				}
			}
			mt.insert(RR), del[LL + 1].push_back(RR);
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; i++){
		for(int j : del[i]) mt.erase(mt.find(j));
		if(mt.size() > 1){
			auto u = mt.begin(); int p = (*u);
			auto v = u; ++v; int q = (*v) - 1;
			int l = p, r = q, ans = q + 1;
			while(l <= r){
				int mid = l + r >> 1;
				if(x[mid] - x[i] > d){
					ans = mid, r = mid - 1;
				}else l = mid + 1;
			}
			sum += q - ans + 1;
		}
	}
	return sum;
}

void S(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int j = i;
		while(j < n && a[j + 1] - a[j] <= d) ++j;
		for(int k = i; k <= j; k++) x[k - i + 1] = a[k];
		ans += check(j - i + 1), i = j;
	}
	cout << ans << '\n';
}

void A(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 1) {cout << "0\n"; return;}
	int del = a[2] - a[1], zrr = d / del;
	if(zrr > 1) cout << max(n - (2 * zrr - 1), 0ll) << '\n'; 
	else cout << "0\n";
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	if(c == 11 || c == 12) while(T--) A();
	else while(T--) S();
	return 0;
}
