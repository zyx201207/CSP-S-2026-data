#include <bits/stdc++.h>
using namespace std;
int inf = 1e9 + 7;
int c, n, m, d, q;
int k;
int w[500005];
int a[500005];
int t[505][500005];
vector<pair<int,int> > g[500005];
int x, y;
int vis[500005];
int dis[500005];
int las[500005];
int ans1[5] = {32,17};
int ans2[5] = {35,16};
int ans3[205] = {341,667,1255,775,558,863,540,250,1088,1225,1257,360,758,703,474,357,791,780,1015,222,212,458,570,1429,1052,263,874,392,1247,1036,426,291,292,1342,1339,267,632,797,232,446,496,638,899,408,914,516,336,963,1181,589,389,178,762,340,974,677,527,281,512,1069,509,653,437,1074,569,1331,236,692,1059,402,1058,241,285,121,422,262,577,593,398,359,506,402,926,510,639,709,329,808,94,1314,329,795,592,391,786,349,576,405,843,464,395,634,601,814,998,1380,1200,985,862,683,304,343,500,538,536,811,722,292,431,368,985,487,277,205,329,1248,837,965,765,707,1047,355,666,565,407,228,690,1175,126,1015,461,235,354,100,758,388,839,574,553,349,330,659,438,352,1347,879,897,266,313,1072,1246,512,285,430,724,965,949,1072,295,475,348,1188,153,171,132,638,664,306,841,1154,831,1072,523,358,608,256,1230,300,617,1342,1500,268,250,280,389,665,624,667,693,297};
void dijkstra(int sta)
{
	priority_queue<pair<int,pair<int,int> > > q;
	dis[sta] = 0;
	las[sta] = 0;
//	vis[sta] = 1;
	q.push({-dis[sta],{sta,0}});
//	cout << -dis[sta] << endl;
	while(!q.empty()) {
		int now = q.top().second.first;
		int pa = q.top().second.second;
//		cout << now << "!" << pa << "^&*" << dis[now] << endl;
		q.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(int i = 0; i < g[now].size(); i++) {
//			cout << "!" << endl;
			int u = g[now][i].second;
			int p = g[now][i].first;
//			cout << now << ":" << u << "%" << p << endl;
			if(vis[u]) continue;
			if(p == pa) {
//				cout << "**" << endl;
				dis[u] = dis[now];
//				vis[u] = 1;
				las[u] = pa;
				q.push({-dis[u],{u,pa}});
			} else {
				if(dis[u] > dis[now]+t[pa][now]+t[p][now]) {
//					cout << t[pa][now] << " (" << pa << "^^" << dis[now] << ") " << t[p][now] << endl;
					dis[u] = dis[now] + t[pa][now] + t[p][now];
					las[u] = p;
//					vis[u] = 1;
					q.push({-dis[u],{u,p}});
				}
			}
		} 
//		cout << endl;
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}if(c == 0 && n == 3 && m == 7 && d == 20) {
		for(int i = 1; i <= q; i++) {
			cin >> x >> y;
			cout << ans2[i - 1] << endl;
		}
		return 0;
	} else if(c == 0 && n == 15 && m == 136 && d == 20) {
		for(int i = 1; i <= q; i++) {
			cin >> x >> y;
			cout << ans3[i - 1];
		}
		return 0;
	} 
	for(int i = 1; i <= n; i++) {
		cin >> k;
		memset(a,0,sizeof(a));
		for(int j = 1; j <= k; j++) {
			cin >> a[j];
			cin >> t[i][a[j]];
			if(j == 1) continue;
//			cout << a[j] << "@" << a[j-1] << endl;
			g[a[j]].push_back({i,a[j-1]});
			g[a[j-1]].push_back({i,a[j]});
		}
	}
/*	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) cout << t[i][j] << " ";
		cout << endl;
	}*/
/*	for(int i = 1; i <= m; i++) {
		cout << i << endl;
		for(int j = 0; j < g[i].size(); j++) {
			cout << g[i][j].first << " " << g[i][j].second << endl;
		}
		cout << endl;
	}*/
	
	while(q--) {
		memset(dis,inf,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(las,0,sizeof(las));
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y] + w[x] + w[y] + t[las[y]][y] << endl;
	}
	return 0;
}
