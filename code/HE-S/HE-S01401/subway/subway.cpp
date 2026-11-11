#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int ans = INT_MAX;
int way[505][500005];
bool vis[505][500005];
queue<pair<int, int>> que;

inline void init() {
	for (int i = 0; i<505; i++) {
		for (int j = 0; j<500005; j++) {
			vis[i][j] =0;
		}
	}

}
int dfs(int line,int now, int time, int sec, int i) {
	if (vis[line][now]) {
		return time;
	}
	if (now == sec)
		return time;
	if (i) {
		for (int i = 0; i<500; i++) {
			if (way[i][now] && i!=line) {
				vis[line][now] =1;
				time = min(time, dfs(i,now,time+way[i][now]+way[line][now],sec,0));
				vis[line][now] =0;
			}
		}
	} else {
		for (int i=0; i<500000; i++) {
			if(way[line][i] && i!=now) {
				vis[line][now] =1;
				time = min(time, dfs(line,i,time,sec,1));
				vis[line][now] =0;
			}
		}
	}
	return time;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;

	for (int i = 0; i<m; i++) {
		cin>>way[501][m];
	}
	for (int i=0; i<n; i++) {
		int k;
		cin>>k;
		for (int j = 0; j<n; j++) {
			int a,t;
			cin>>a>>t;
			way[i][a]=t;
		}
	}
	for (int i=0; i<q; i++) {
		int st,ed;
		cin>>st>>ed;
		que.push({st,ed});
	}
	for (int i=0; i<q; i++) {
		init();
		pair<int, int> a;
		a = que.front();
		que.pop();
		ans += way[501][a.first];
		ans += way[501][a.second];
		int now = a.first;
		if (c>4) {
			cout<<ans;
			return 0;
		}
		for (int j = 0; j<500; j++) {
			ans = min(ans, dfs(i,now,0,a.second,0));
			ans = min(ans, dfs(i,now,0,a.second,1));

		}
		ans = max(way[501][a.first]+way[501][a.second],ans);
		cout<<ans<<endl;
	}

	return 0;
}

/*
0 2 5 20 2
  4 1 9 2 5
  3 1 5  2 7 4 6
  3 2 3 3 4 5 7
  1 3
  1 2

*/
