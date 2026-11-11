#include <bits/stdc++.h>
using namespace std;
long long c, n, m, k[501], d, q, x, y, w[500001], a[501][21], t[501][21], ans[500001];
vector<int>e[500001];
void zdl(int s){
	queue<int>q;
	ans[s] = 0;
	q.push(s);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i : e[x]){
			for(int j = 1; j <= k[i]; j++){
				if(ans[a[i][j]] > ans[x]+t[i][x]+t[i][a[i][j]]){
					ans[a[i][j]] = ans[x]+t[i][x]+t[i][a[i][j]];
					q.push(a[i][j]);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> c;
	if(c != 0) return 0;
	cin >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)	cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			e[a[i][j]].push_back(i);
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		memset(ans,0x3f3f3f3f3f3f3f3f,sizeof(ans));
		zdl(x);
		cout << ans[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
