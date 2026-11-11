#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,m;
int a[N];
int ans = 0; 
void dfs(int i,int sum,int yi) {
	if (yi == m) {
		ans = max(ans,sum);
		return;
	}
	if (i == n + 1) return;
	dfs(i + 1,sum & a[i],yi + 1);
	dfs(i + 1,sum,yi);
}
signed main() {
	freopen("and.in", "r" ,stdin);
	freopen("and.out", "w" ,stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++) dfs(i + 1,a[i],1);
	cout<<ans<<"\n";
	return 0;
}
