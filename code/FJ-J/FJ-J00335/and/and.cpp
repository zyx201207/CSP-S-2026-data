#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N],ans = -1e9;
void dfs(int cnt,int i,int sum){
	if (cnt == m){
		ans = max(ans,sum);
		// cout << sum << "\n";
		return;
	}
	if (i == n){
		return;
	}
	if (cnt == 1){
		dfs(cnt + 1,i + 1,a[i]);
		dfs(cnt,i + 1,a[i]);
	}
	else{
		dfs(cnt + 1,i + 1,sum & a[i]);
		dfs(cnt,i + 1,sum);
	}
	// cout << cnt << "\n";
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(0,1,0);
	cout << ans;
	return 0;
}
