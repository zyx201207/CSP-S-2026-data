#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 2e6 + 7; 
int n, x[M], d;

void solve(){
	cin >> n >> d;
	int ans = 0;
	for(int i = 1; i <= n; i ++) cin >> x[i];
	for(int l = 1; l <= n; l ++){
		for(int r = l + 1; r <= n; r ++){
			vector<int> fwd, bwd;
			fwd.push_back(l);
			bool ok = true;
			for(int i = 0; ; i ++){
				for(int j = fwd[i]; j <= r; j ++){
					if(j == r || x[j + 1] - x[fwd[i]] > d){
						if(j == fwd[i]) ok = false;
						fwd.push_back(j);
						break;
					}
				}
				if(!ok) break;
				if(fwd.back() == r) break;
			}
			if(!ok) continue;
			
			ok = true;
			
			bwd.push_back(r);
			for(int i = 0; ; i ++){
				for(int j = bwd[i]; j >= l; j --){
					if(j == l || x[bwd[i]] - x[j - 1] > d){
						if(j == bwd[i]) ok = false;
						bwd.push_back(j);
						break;
					}
				}
				if(!ok) break;
				if(bwd.back() == l) break;
			}
			
			
			if(fwd.size() != bwd.size()) continue;
			reverse(fwd.begin(), fwd.end());
			
			
			ok = false;
			for(int i = 0; i < (int)fwd.size(); i ++){
				if(fwd[i] != bwd[i]){
					if(ok){
						ok = false;
						break;
					}
					if(abs(fwd[i] - bwd[i]) != 1){
						ok = false;
						break;
					}
					ok = true;
				}
			}
			if(ok) ans ++;
		}
	}
	cout << ans << "\n";
}

void solv(){
	cin >> n >> d;
	for(int i = 1; i <= n; i ++) cin >> x[i];
	if(n == 1) return cout << "0\n", void();
	d /= (x[2] - x[1]);
	if(d <= 1) return cout << "0\n", void();
	d = 2 * d - 1;
	cout << max(0ll, n - d) << "\n";
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	int c, t; cin >> c >> t;
	while(t --){
		if(c <= 6) solve();
		else solv();
	}
	
	return 0;
}

