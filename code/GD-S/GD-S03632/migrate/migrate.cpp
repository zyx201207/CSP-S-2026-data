#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define cfalse cin.tie(0)->sync_with_stdio(0)
const int maxn = 6e5 + 5;
const int inf = 1e18;
int c, n, d;
vector<int>t;
int ck(int l, int r){
//	cout << "l: " << l << ' ' << "r: " << r << endl;
	int minn = 0;
	int las = 0, lp = l;
	for(int i = l; i <= r; i++){
		int ll = i, rr = r + 1;
		while(ll + 1 < rr){
			int mid = (ll + rr) >> 1;
			if(t[mid] - t[i] > d) rr = mid;
			else ll = mid;
		}
		i = ll;
		minn++;
//		cout << i << ' ';
	}
//	cout << "minn: " << minn << endl;
	vector<int>dp(r - l + 5, 0); 
	for(int i = l + 1; i <= r; i++){
		int ll = l - 1, rr = i;
		while(ll + 1 < rr){
			int mid = (ll + rr) >> 1;
			if(t[i] - t[mid] <= d) rr = mid;
			else ll = mid;
		}
		dp[i - l] = dp[rr - l] + 1;
	}
	int ll = l - 1, rr = r;
	while(ll + 1 < rr){
		int mid = (ll + rr) >> 1;
		if(t[r] - t[mid] <= d) rr = mid;
		else ll = mid;
	}
	int sum = 0;
	for(int i = rr; i < r; i++){
		if(dp[i - l] + 1 == minn) sum++;
	}
//	cout << "dp: " << endl;
//	for(int i = 0; i < r - l + 1; i++) cout << dp[i] << ' ';
//	cout << endl; 
	if(sum == 2) return 1;
	else return 0;
}
void solve1(){
	t.clear();
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		t.push_back(x); 
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ans += ck(i, j);
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T;
	cin >> c >> T;
	while(T--) {
		solve1();
	}
    return 0;
}
