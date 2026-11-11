#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n, m, ans = -1;
int res[200005], a[200005];
bool u[200005];
void dfs(int p){
	if(p > m){
		int t = res[1];
		for(int i = 2; i <= m; i++)
			t &= res[i];
		ans = max(ans, t);
		return;
	}
	for(int i = 1; i <= n; i++)
		if(!u[i]){
			res[p] = a[i];
			u[i] = 1;
			dfs(p + 1);
			u[i] = 0;
		}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(u, 0, sizeof(u));
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n <= 6667){
		dfs(1);
		cout << ans << endl;
	}else{
		sort(a + 1, a + n + 1);
		if(n & 1) cout << a[n / 2 + 1] << endl;
		else cout << a[n / 2] << endl;
	}
	return 0;
}
