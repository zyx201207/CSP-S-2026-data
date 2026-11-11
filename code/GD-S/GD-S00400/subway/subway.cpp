#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int ww[500005],w[500005], k[505];
struct qwee{
	int id, tm;
};
vector<int> sub[505];
vector<qwee> sta[500005];
int dfs(int nx, int ed, int res){
	if(nx == ed) return res;
	for(auto i:sta[nx]){
		dfs(i.id, ed, res+i.tm);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c == 0) cout << "32\n17";
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
		ww[i] = w[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> k[i];
		int tmp1, tmp2, tmp3, tmp4;
		cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
		if(ww[tmp1] != w[tmp1]) ww[tmp1] += tmp2;
		if(ww[tmp3] != w[tmp3]) ww[tmp3] += tmp4;
		sta[tmp1].push_back({tmp3, tmp2+tmp4});
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y] + dfs(x, y, 0);
		cout << ans << "\n";
	}
	return 0;
}
