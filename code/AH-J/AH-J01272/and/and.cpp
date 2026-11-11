#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5+10;
int dp[N],a[N],maxn = 0,n,m;
void dfs(int dep,int num,int k){
	if(k == m) {
		maxn = max(maxn,num);
		return ;
	}
	if(dep >= n) {
		return ;
	}
	if(num == 0){
		dfs(dep+1,a[dep],1);
		dfs(dep+1,0,0);
	}
	else{
		dfs(dep+1,num and a[dep],k+1);
		dfs(dep+1,num,k);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	int ans = 0,ans2 = 0;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		ans = max(ans,a[i]);
		if(i == 1) ans2 = a[i];
		else ans2 &= a[i];
	}
	
	if(m == 1){
		cout << ans << endl;
		return 0;
	}
	if(m == n){
		cout << ans2 << endl;
		return 0;
	}
	
	if(m == 2){
		int tmp = 0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				tmp = max(tmp,a[i] & a[j]);
			}
		}
		cout << tmp << endl;
		return 0;
	}
	if(n <= 20) {
		dfs(1,0,0);
		cout << maxn << endl;
		return 0;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}
//mina:Trick||Treat!
