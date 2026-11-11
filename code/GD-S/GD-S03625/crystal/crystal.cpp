#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N];
int pre[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	pre[1] = 0;
	for(int i = 2; i <= n; ++ i){
		pre[i] = pre[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	
//	for(int i = 1; i <= n; ++ i) cout << pre[i] << ' ';
	
//	cout << "2968:" << a[2973] << '\n';
//	cout << "3418:" << a[3418] << '\n';
	
	int ans = 0, res = 0;
	int l = 1;
	for(int i = 2; i <= n; ++ i){
		res = pre[i] - (a[i] - a[l]) * (l - 1);
//		cout << res << '\n';
		while(res > m){
			res -= (a[i] - a[l]);
			++ l;
		}
		
//		if(i == 318248) cout << res << '\n';
		
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	
	return 0;
}
