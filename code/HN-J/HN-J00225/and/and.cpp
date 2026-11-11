#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n, m, maxn = -1e18, a[N];
void dfs(int step, int kk, int sum){
	if(step > n){
		if(kk == m) maxn = max(maxn, sum);
		return ;
	}
	if(kk > m) return ;
	if(sum == 0) dfs(step + 1, kk + 1, a[step]);
	else dfs(step + 1, kk + 1, sum & a[step]);
	dfs(step + 1, kk, sum);
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0, 0);
    cout << maxn << '\n';
	return 0;
}
