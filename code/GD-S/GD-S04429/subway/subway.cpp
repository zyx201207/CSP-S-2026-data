#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Station {
	int time;
	vector<pair<int,int>>subway;
};

struct Subway {
	int k;
	vector<pair<int,int>>station;
};
vector<Station>station;
vector<Subway>subway;
vector<bool>b;

int dfs(int x,int y) {
	if(b[x])return INT_MAX;
	if(x==y)return 0;
	int minn = INT_MAX;
	for(auto hx : station[x].subway) {
		for(auto xh : subway[hx.first].station) {
			b[x] = true;
			minn = min(minn,hx.second + xh.second + dfs(xh.first,y));
			b[x] = false;
		}
	}
	return minn;
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	station.resize(m+1);
	subway.resize(n+1);
	b.resize(n+1);
	for(int i=1; i<=m; i++)
		cin >> station[i].time;
	for(int i=1; i<=n; i++) {
		cin >> subway[i].k;
		for(int j=1; j<=subway[i].k; j++) {
			int kkk,kkkk;
			cin >> kkk >> kkkk;
			subway[i].station.push_back({kkk,kkkk});
			station[kkk].subway.push_back({i,kkkk});
		}
	}
	while(q--) {
		int l,r;
		cin >> l >> r;
		int all_time = station[l].time + station[r].time;
		all_time+=dfs(l,r);
		cout<<all_time<<endl;
	}
	return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
