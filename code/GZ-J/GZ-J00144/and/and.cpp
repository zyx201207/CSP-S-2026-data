//GZ-J00144  张心恬  贵阳市白云区华师一学校
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long a[N], ans;
void dfs(int p, long long sum, int cnt){
	if (cnt == m){
		ans = max(ans, sum);
		return ; 
	}
	if (p == n + 1 || cnt > m) return ;
	if (cnt == 0){
		dfs(p + 1, a[p], cnt + 1);
	}
	else{
		dfs(p + 1, sum & a[p], cnt + 1);
	}
	dfs(p + 1, sum, cnt);
	return ;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ){
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
} 
