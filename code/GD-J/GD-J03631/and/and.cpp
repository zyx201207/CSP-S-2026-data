#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 2e5 + 5;
int n, m;
ll a[MAXN];
ll ans = -0x3f3f3f3f;

void dfs(int len, int cur, ll asum){
	if((cur + 1) == n){
		if(len == m){
			ans = max(ans, asum);
		}
		return;
	}
	if(len == 0){
		dfs(len + 1, cur + 1, a[cur]);
	}else{
		dfs(len + 1, cur + 1, asum & a[cur]);
	}
	dfs(len, cur + 1, asum);
}

bool cmp(int a, int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	bool f = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f &= (a[i] == i - 1);
	}
	if(m == 1){
		ll mx = -0x3f3f3f3f;
		for(int i = 1; i <= n; i++){
			mx = max(mx, a[i]);
		}
		cout << mx;
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(int i = 1; i <= n; i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(f){
		if(m == n) cout << 0;
		else{
			sort(a + 1, a + n + 1, cmp);
			ans = a[1];
			for(int i = 1; i <= m; i++){
				ans &= a[i];
			}
		}
		cout << ans;
		return 0;
	}
	if(n <= 20){
		dfs(0, 1, 0);
		cout << ans;
		return 0;
	}
	
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	for(int i = 1; i <= m; i++){
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
