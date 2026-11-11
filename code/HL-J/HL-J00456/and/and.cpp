#include <bits/stdc++.h>
using namespace std;
//dfs
int n, m, a[200005], ans;
void dfs(int x, int res, int turn){
	//cout << a[x] << ' ';
	if(turn == m) {
	//	cout << "res:" << res << endl;
		ans = max(ans, res);
		return ;
	}
	for(int k = x+1; k<=n; k++){
		dfs(k, res&a[k], turn+1);
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin); //¼ÇµÃ½â³ý£¡£¡ 
    freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n-m+1; i++){
		dfs(i, a[i], 1);
	}
	cout << ans;
	return 0; 
}
