#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int c, n, m, d, q, w[500005], k[505];
vector <int> a[501], t[501];
vector <bool> vis[501];
int v[500005];
bool vvis[505];

void work(){
	int x, y, ans;
	cin >> x >> y;
	memset(v, 0x3f, sizeof(v));
	memset(vvis, 0, sizeof(vvis));
	priority_queue < pii, vector<pii>, greater<pii> > q;
	q.push({0, x});
	v[x] = 0;
	while(q.size()){
		int dis = q.top().first, u = q.top().second;
		if(u == y){
			ans = dis;
			break;
		}
		for(int i = 1; i <= n; i++){
			if(vis[i][u] && !vvis[i]){
				vvis[i] = 1;
				for(int j = 1; j <= k[i]; j++){
					int x = a[i][j];
					if(v[x] > dis + 1){
						v[x] = dis + 1;
						q.push({dis + 1, x});
					}
				}
			}
		}
	}
	cout << w[x] + w[y] + 2 * ans * t[1][1] << endl;
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)	cin >> w[i];
	
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
//			vis[i][a[i][j]] = 1;
		}
	}
	while(q--)	work();
	
	return 0;
}

