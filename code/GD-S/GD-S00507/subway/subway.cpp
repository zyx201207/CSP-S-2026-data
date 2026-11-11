#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100010];
long long a[5010][5010],t[10][100010];
bool f[5010][5010];
int dfs(int u,int end,int ans){
	if (u = end) return ans;
	for (int i = 1; i <= 5010; i ++){
		if (a[u][i] == 0 || f[u][i])
			continue;
		ans = dfs(i,end,ans+t[1][u]);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i ++) cin >> w[i];
	for (int i = 1,u,v,sub; i <= m; i ++){
		cin >> sub;
		for (int j = 1; j <= sub; j ++){
			cin >> u >> t[sub][u];
		}
		for (int j = 1; j <= sub; j ++){
			for (int k = 1; k <= sub; k ++){
				if (j == k) continue;
				a[j][k] = a[k][j] = 1;	
			}
		}
	}
	for (int i = 1,start,end; i <= c; i ++){
		cin >> start >> end;
		cout << dfs(start,end,w[start]) + w[end];
		cout << endl;
	}
	return 0;
}
