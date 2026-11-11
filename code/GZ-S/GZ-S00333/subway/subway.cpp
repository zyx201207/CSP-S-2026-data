//GZ-S00333,lijunshen
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
int c, n, m, d, q;
int w[500005];
int k;
vector<pii>t[500005];
int a, tmp;
int x, y;
int e[505][505];
int l1, l2, t1, t2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i)cin >> w[i];
	for(int i = 1;i <= n;++i){
		cin >> k;
		for (int j = 1;j <= k;j++){
			cin >> a >> tmp;
			t[a].push_back((pii){i, tmp});
		}
	}
	for (int i = 1;i <= n;++i){
		for (int j = 1;j <= n;j++){
			e[i][j] = 1e18;
		}
	}
	for (int i = 1;i <= m;++i){
		for (int j = 0;j < t[i].size();j++){
			//cout << i << ' ' << t[i][j].first << ' ' << t[i][j].second << '\t';
			for (int k = j;k < t[i].size();k++){
				l1 = t[i][j].first;
				t1 = t[i][j].second;
				l2 = t[i][k].first;
				t2 = t[i][k].second;
				//cout << t1 << ' ' << t2 << ' ' << e[l1][l2] << endl;
				if (l1 == l2)e[l1][l2] = 0;
				else{
					e[l1][l2] = min(e[l1][l2], t1+t2);
					e[l2][l1] = min(e[l2][l1], t2+t1);
				}
			}
		}
	}
	while (true){
		bool bet = false;
		for (int i = 1;i <= n;++i){
			for (int j = 1;j <= n;j++){
				for (int k = 1;k <= n;k++){
					if (e[i][k]+e[k][j] < e[i][j]){
						bet = true;
						e[i][j] = e[i][k]+e[k][j]; 
					}
				}
			}
		}
		if (!bet)break;
	}
	int mn, tm;
	for (int i = 1;i <= q;++i){
		cin >> x >> y;
		mn = 1e18;
		for (int j = 0;j < t[x].size();j++){
			for (int k = 0;k < t[y].size();k++){
				l1 = t[x][j].first;
				t1 = t[x][j].second;
				l2 = t[y][k].first;
				t2 = t[y][k].second;
				tm = w[x]+t1+e[l1][l2]+t2+w[y];
				mn = min(tm, mn);
			}
		}
		cout << mn << '\n';
	}
	return 0;
}
