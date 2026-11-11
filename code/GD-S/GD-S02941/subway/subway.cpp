#include <bits/stdc++.h>
#define int long long
#define fir first
#define sec second
#define INF 1000000005
using namespace std;
int c, n, m, d, q;
vector< int > w;
vector< vector<int> > sgl; // sgl[i]: 站点i有哪些线路经过 
vector< vector<pair<int, int>> > sta;
// w[出站时间]
// sta[线路k][{站点a，到达站厅t}]
vector< vector<int> > ed; // 线路的邻接矩阵 

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	w.resize(m);
	sgl.resize(m);
	sta.resize(n);
	ed.resize(n, vector<int>(n, INF));
//	int ed[505][505];
//	memset(ed, 0x3f, sizeof ed);
	for (int i = 0; i < m; i++) cin >> w[i];
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		sta[i].resize(k);
		for (int j = 0; j < k; j++){
			int tpa, tpb;
			cin >> tpa >> tpb;
			sta[i].push_back(make_pair(tpa, tpb)); 
			sgl[tpa].push_back(i);
		}
	}
	
	// 建邻接表 
	for (int k = 0; k < m; k++){
		int sz = sgl[k].size();
		if(sz == 1) continue;
		for (int i = 0; i < sz - 1; i++){ // sz < 20
			for (int j = i + 1; j < sz; j++){
				int val = 0;
				int sz1 = sta[i].size();
				for (int xx = 0; xx < sz1; xx++){
					pair<int, int> x = sta[i][xx];
					if(x.fir == k){
						val += x.sec;
						break; 
					}
				}
				int sz2 = sta[j].size();
				for (int xx = 0; xx < sz2; xx++){
					pair<int, int> x = sta[j][xx];
					if(x.fir == k){
						val += x.sec;
						break; 
					}
				}
				ed[i][j] = min(ed[i][j], val);
				ed[j][i] = ed[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cerr << ed[i][j] << " ";
		}
		cerr << "\n";
	}
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if(ed[i][j] > ed[i][k] + ed[k][j]){
					ed[i][j] = ed[i][k] + ed[k][j];
				}
			}
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		int ans = ed[u][v] + w[u] + w[v] + 
		cout << ans << '\n';
	}
	return 0;
}
