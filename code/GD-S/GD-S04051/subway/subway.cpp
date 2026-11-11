#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
const int MPN = 505;
const int MEN = 5e5 + 5;
int c, n, m, d, q;
int wk[MPN];
int dis[MPN];
struct linee{
	int pass;
	int itt;
};
vector <int> a[MPN];
vector <int> b[MPN];
linee ed[MEN];
priority_queue <pii, vector <pii>, greater <pii> > pq;
void dij(int sta){
	pq.push({0, sta});
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for (int i = 0; i < a[u].size(); i++){
			int v = a[u][i];
			if (dis[v] > dis[u] + b[u][i]){
				dis[v] = dis[u] + b[u][i];
				pq.push({dis[v], v});
			}
		}
	}
} 
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> wk[i];
	}
	for (int i = 1; i <= n; i++){
		int k; cin >> k;
		int cnt = 0;
		while (k--){
			int stt, tm; cin >> stt >> tm;
			cnt++;
			ed[cnt].pass = stt;
			ed[cnt].itt = tm;
		}
		for (int i = 1; i < cnt; i++){
			a[ed[i].pass].push_back(ed[i + 1].pass);
			a[ed[i + 1].pass].push_back(ed[i].pass);
			b[ed[i].pass].push_back(ed[i].itt + ed[i + 1].itt);
			b[ed[i + 1].pass].push_back(ed[i].itt + ed[i + 1].itt);
		}
	}
	while (q--){
		int start, end; cin >> start >> end;
		memset(dis, 0x3f, sizeof(dis));
		dis[start] = 0;
		dij(start);
		cout << dis[end] + wk[start] + wk[end] << "\n";
	}
	return 0;
} 
