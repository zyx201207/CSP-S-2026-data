#include<bits/stdc++.h>
using namespace std;

const int N = 5e5;
const long long inf = 1e18 + 7;
struct table{
	long long lct, time;
	friend bool operator < (table a, table b){
		return a.lct < b.lct;
	}
}y[N + 5];
vector <table> a[N + 5], bl[N + 5], p[505];
priority_queue <table> q;
int T, n, m, d, qt, st, en, vis[505], w[N + 5], l[N + 5];
long long ans, dis[505][505];

bool cmp(table a, table b){
	return a.lct < b.lct;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin >> T >> n >> m >> d >> qt;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> l[i];
		for(int j = 1; j <= l[i]; j++){
			cin >> st >> en;
			y[j] = ((table){st, en});
			bl[st].push_back((table){i, en});
		}
		sort(y + 1, y + l[i] + 1, cmp);
		for(int j = 1; j <= l[i]; j++)
			a[i].push_back(y[j]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			for(int x1 = 0, x2 = 0; x1 < l[i]; x1++){
				while(a[j][x2].lct < a[i][x1].lct && x2 < l[j])
					x2++;
				if(a[j][x2].lct == a[i][x1].lct){
					p[i].emplace_back((table){j, a[i][x1].time + a[j][x2].time});
					p[j].emplace_back((table){i, a[i][x1].time + a[j][x2].time});
				}
			}
		}
	}
	/*for(int i = 1; i <= n; i++){
		cout << "!" << i << "\n";
		for(table j : p[i])
			cout << j.lct << " " << j.time << "\n";
	}*/
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = inf;
			vis[j] = 0;
		}
		dis[i][i] = 0;
		while(!q.empty())
			q.pop();
		q.push((table){0, i});
		while(!q.empty()){
			int t = q.top().time;
			q.pop();
			for(table j : p[t]){
				if(dis[i][j.lct] > dis[i][t] + j.time){
					dis[i][j.lct] = dis[i][t] + j.time;
					if(!vis[j.lct]){
						vis[j.lct] = 1;
						q.push((table){dis[i][j.lct], j.lct});
					}
				}
			}
		}
	}
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout << dis[i][j] << " ";
		cout << "\n";
	}*/
	for(int i = 1; i <= qt; i++){
		cin >> st >> en;
		ans = inf;
		for(table j : bl[st]){
			for(table k : bl[en]){
				ans = min(ans, dis[j.lct][k.lct] + j.time + k.time);
			}
		}
		ans += w[st] + w[en];
		cout << ans << "\n";
	}
	return 0;
}
