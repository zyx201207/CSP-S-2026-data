#include<bits/stdc++.h>
#define int long long
#define N 505
#define M 1005

using namespace std;

struct cai{
	int v,w;
	bool operator > (const cai& nx) const {
		return w > nx.w;
	}
	bool operator < (const cai& nx) const {
		return w < nx.w;
	}
};
int c,n,m,d,q,w[M],k[N],dis[M][M];
vector<int>a[N],t[N];
vector<cai>p[M];
priority_queue<cai,vector<cai>,greater<cai> >que;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1,x,y;j <= k[i];j++){
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int l = 1;l <= k[i];l++){
			for(int r = l + 1;r <= k[i];r++){
				p[a[i][l - 1]].push_back({a[i][r - 1],t[i][l - 1] + t[i][r - 1]});
				p[a[i][r - 1]].push_back({a[i][l - 1],t[i][l - 1] + t[i][r - 1]});
			}
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++)if(j != i)dis[i][j] = 1e18;
		que.push({i,0});
		while(!que.empty()){
			cai now = que.top();
			que.pop();
			if(dis[i][now.v] < now.w)continue;
			for(cai nx : p[now.v]){
				int diss = dis[i][now.v] + nx.w;
				if(diss < dis[i][nx.v]){
					dis[i][nx.v] = diss;
					que.push({nx.v,diss});
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x] + w[y] + dis[x][y] << "\n";
	}
	return 0;
}
