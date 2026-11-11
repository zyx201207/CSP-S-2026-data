#include <iostream>
typedef long long ll;
using namespace std;
int n, m;
ll a[200010];
ll maxx(ll a, ll b){
	return (a > b)? a : b;
}
ll b[200010];
ll ans;
void dfs(int id, int last){
	if(id == m + 1){
		ll tmp = b[1];
		for(int i = 2; i <= m; i++) tmp = tmp & b[i];
		ans = maxx(ans, tmp);
		return;
	}
	if(m - id + last > n) return;
	for(int i = last; i <= n; i++){
		dfs(id, i + 1);
		b[id] = a[i];
		dfs(id + 1, i + 1);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 1);
	cout << ans;
	return 0;
}
