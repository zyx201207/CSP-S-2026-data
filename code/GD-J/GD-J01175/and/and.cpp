#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n , m , a[N] , ma;
bool v[N];
void dfs(int x , int sum) {
	if (x > m) {
		ma = max(ma , sum);
		return ;
	}
	for (int i = x; i <= n; i++) {
		if (v[i]) continue;
		v[i] = 1;
		if (x == 1) dfs(x + 1 , a[i]);
		else dfs(x + 1 , sum & a[i]);
		v[i] = 0;
	}
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out", "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	dfs(1 , 0);
	cout << ma;
	return 0;
}
