#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500005],e[200][400],t[200][400];
int x,y,sum;
void dfs(int a,int b){
	if (b == y) return; 
	if (e[a][b] != 0) {
		sum += t[a][b];
		dfs(b,b);
		dfs(b,b+1);
	}
	else dfs(a,b+1);
}
signed main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			cin >> e[i][j] >> t[i][j];
		}
	}
	int ans;
	while (q--){
		cin >> x >> y;
		ans = w[x]+w[y];
		dfs(x,x);
		cout << ans + sum << "\n";
	}
	return 0;
}
