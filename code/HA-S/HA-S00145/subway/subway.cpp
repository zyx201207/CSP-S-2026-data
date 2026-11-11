#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005], xia[100], xiat[100];
vector<int> a[505];
map<pair<int, int>, ll> t;
queue<pair<int, int> > q;
ll bfs(int x, int last, int y){
	pair<int, int> now, nw;
	for(int i = 0; i < a[x].size(); i++){
		if(a[x][i] == y){
			now = make_pair(x, y);
			return t[now];
		}
		if(a[x][i] == last)
			continue;
		now = make_pair(a[x][i], x);
		q.push(now);
	}
	while(!q.empty()){
		nw = q.front();
		q.pop();
		return bfs(nw.first, nw.second, y) + t[nw];
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int c, n, m, d, qu, k;
	cin >> c >> n >> m >> d >> qu;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		memset(xia, 0, sizeof(xia));
		memset(xiat, 0, sizeof(xiat));
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> xia[j] >> xiat[j];
		}
		pair<int, int> now;
		for(int j = 1; j <= k; j++){
			for(int j2 = j + 1; j2 <= k; j2++){
				if(j == j2)
					continue;
				a[xia[j]].push_back(xia[j2]);
				a[xia[j2]].push_back(xia[j]);
				now = make_pair(xia[j], xia[j2]);
				t[now] = xiat[j] + xiat[j2];
				now = make_pair(xia[j2], xia[j]);
				t[now] = xiat[j] + xiat[j2];
			}
		}
	}
	int x, y;
	for(int i = 1; i <= qu; i++){
		cin >> x >> y;
		ll ans = bfs(x, x, y) + w[x] + w[y];
		cout << ans << '\n';
	}
//	0 4 5 2 1
//	5 0 0 0 5
//	2 1 1 2 1
//	2 2 1 3 1
//	2 3 1 4 1
//	2 4 1 5 1
//	1 5
	return 0;
}
