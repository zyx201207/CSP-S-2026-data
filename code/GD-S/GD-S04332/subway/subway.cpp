#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = INT_MAX;
int w[500001], t[501][50001], a[501][50001];
vector<pair<int, int> > v[50001 + 501];
queue<pair<int, int> > q;
pair<bool, int> f[50001];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int ki;
		cin >> ki;
		for (int j = 1; j <= ki; j++){
			cin >> a[i][j] >> t[i][j];
			v[a[i][j]].push_back(make_pair(m + i, t[i][j]));
			v[m + i].push_back(make_pair(a[i][j], t[i][j]));
		}
	}
	while(p--){
		int minn = INF;
		memset(f, 0, sizeof(f));
		while(!q.empty())q.pop();
		int s, t;
		cin >> s >> t;
		q.push(make_pair(s, 0));
		f[s] = make_pair(1, 0);
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == t){
				minn = min(minn, y);
				continue;
			}
			for (int i = 0; i < v[x].size(); i++){
				int u = v[x][i].first, k = v[x][i].second;
				if (f[u].first == 1){
					if(k + y < f[u].second){
						f[u].second = k + y;
						q.push(make_pair(u, k + y));
					}
				}
				else{
					q.push(make_pair(u, k + y));
					f[u].first = 1;
					f[u].second = k + y;
				}
			}
		}
		cout<< minn + w[s] + w[t] << '\n';
	}
}
