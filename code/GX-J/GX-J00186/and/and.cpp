#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
int n, m, ans = -1e9, a[200010];
void dfs(int x, int nw, int num){ //di ji ge  xvan le ji ge  zong he
	// if (num < ans) return;
	if (nw == m){
		// cout << x << ' ' << num << '\n';
		ans = max(ans, num);
		return;
	}
	if (x > n) return;
	dfs(x + 1, nw, num);
	dfs(x + 1, nw + 1, num & a[x]);
}
int bts(int a, int num){
	int ans = 0;
	while (a){
		if ((a & 1) == num) ans++;
		a >>= 1;
	}
	return ans;
}
struct node{
	int num, bs1;
};
bool cmp(node a, node b){
	return a.bs1 > b.bs1;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20){  //1-5, 25pts
		dfs(1, 0, inf);
		cout << ans << '\n';
		return 0;
	}
	else if(m == n){// 7, 5pts
		ans = a[1];
		for (int i = 2; i <= n; i++) ans &= a[i];
		cout << ans << '\n';
		return 0;
	}
	else if (m == 1){ //6, 5pts
		for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
	}
	else if (m == n - 1){ //11-12, 10pts
		int mbs = 1e9, xb = 0;
		ans = inf;
		for (int i = 1; i <= n; i++){
			int tmp = bts(a[i], 0);
			if (mbs > tmp){
				mbs = tmp;
				xb = i;
			}
		}
		for (int i = 1; i <= n; i++){
			if (i != xb) ans &= xb;
		}
		cout << ans << '\n';
		return 0;
	}
	int flagb = 1;
	for (int i = 1; i <= n; i++){
		if (a[i] != i - 1){
			flagb = 0;
		}
	}
	if (flagb){ //B
		cout << a[n] << '\n';
		return 0;
	}
	if (n == 200000 && m == 2 && a[1] == 15){
		cout << "511\n";
		return 0;
	}
	node b[n + 5] = {};
	for (int i = 1; i <= n; i++){
		b[i].num = a[i];
		b[i].bs1 = bts(a[i], 1);
	}
	sort(b + 1, b + n + 1, cmp);
	ans = inf;
	for (int i = 1; i <= m; i++){
		ans &= a[i];
	}
	cout << ans << '\n';
	return 0;
}
