#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[200005];
int ans = -1;
void dfs(int id, int cnt, int sum){
	if(cnt+(n-id+1) < m) return;
	if(cnt == m){
		ans = max(ans, sum);
		return;
	}
	dfs(id+1,cnt+1,sum&a[id]);
	dfs(id+1,cnt,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	dfs(1,0,-1);
	cout << ans;
	return 0;
}

