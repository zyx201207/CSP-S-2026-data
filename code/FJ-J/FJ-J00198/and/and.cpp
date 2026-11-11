#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int res;
int n, m;
int a[N];
void dfs(int cen, int nt, int no){
	if(cen == m){
		res = max(res, no);
		return;
	}
	for(int i = nt + 1; i <= n; i ++){
		dfs(cen + 1, i, no & a[i]);
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(m == 1){
		int maxn = 0;
		for(int i = 1; i <= n; i ++){
			int x;
			cin >> x;
			maxn = max(x, maxn);
		}
		cout << maxn;
		return 0;
	}
	else if(m == n){
		int ans;
		cin >> ans;
		for(int i = 2; i <= n; i ++){
			int x;
			cin >> x;
			ans &= x;
		}		
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n - m + 1; i ++){
		dfs(1, i, a[i]);
	}
	cout << res;
	return 0;
}
