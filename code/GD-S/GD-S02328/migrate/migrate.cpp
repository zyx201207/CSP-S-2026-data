#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
int c, T, n, d, ans, x[N];
vector<pair<int, int>> ve;
void solve(){
	cin >> n >> d;
	int dc = 1, dis = 0;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
		dis = x[i]-x[i-1];
		if(i != 1)
			if(x[i]-x[i-1] != dis) dc = 0;
	}
	if(dc){
		if(dis >= d){
			cout << 0 << "\n";
			return ;
		}
		if(d/4-1 > dis){
			cout << 0 << "\n";
			return ;
		}
		if(dis >= (d+2)/3){
			cout << n-5 << "\n";
			return ;
		}
		if(dis < d){
			cout << n-3 << "\n";
			return ;
		}
		cout << 0 << "\n";
	}
	ans = 0, ve.clear();
	for(int i = 1; i <= n; i++){
		for(int j = i+3; j <= n; j++){
			if(x[j]-x[i] <= d) continue;
			if(x[j]-x[i] > 2*d) break;
			int pos = i+1, cnt = 0;
			while(pos < j){
				if(x[pos]-x[i] <= d && x[j]-x[pos] <= d) cnt++;
				pos++; 
			}
			if(cnt == 2) ans++, ve.push_back({i, j});
		}
	}
	for(auto i:ve){
		int l = i.first, r = i.second;
		int cntl = 0, cntr = 0;
		while(l > 0){
			bool f = 0;
			if(x[l]-x[l-1] == d) cntl++, l--, f = 1;
			if(l == 1) break;
			if(x[l]-x[l-1] <= d && x[l-1]-x[l-2] <= d && x[l]-x[l-2] > d) cntl += 2, l -= 2, f = 1;
			if(!f) break;
		}
		while(r <= n){
			bool f = 0;
			if(x[r+1]-x[r] == d) cntr++, r++, f = 1;
			if(r == n-1) break;
			if(x[r+1]-x[r] <= d && x[r+2]-x[r+1] <= d && x[r+2]-x[r] > d) cntr += 2, r += 2, f = 1;
			if(!f) break;
		}
		if(cntl == 0) ans += cntr;
		else if(cntr == 0) ans += cntl;
		else ans += cntl*cntr;
	}
	cout << ans << "\n";
	return ;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
