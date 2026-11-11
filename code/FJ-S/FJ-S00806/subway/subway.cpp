#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

int c,n,m,d,q;
int w[(int)(5e5+5)];
struct Edge{
	int v,w;
};vector<Edge> vct[(int)(5e5+505)];
int x,y;
struct Point{
	int p,dis;
	bool operator<(const Point& oth) const
	{return this->dis>oth.dis;}
};priority_queue<Point> pq;
map<int,int> mp[(int)(5e5+505)];
bool vis[(int)(5e5+505)];
int Dis[(int)(5e5+505)];

void Dijk(){
	while (!pq.empty()) pq.pop();
	memset(Dis,0x3f,sizeof(Dis));
	memset(vis,0,sizeof(vis));
	Dis[x]=0;pq.push({x,0});
	while (!pq.empty()){
		Point now=pq.top();
		pq.pop();
		if (now.p==y) break;
		if (vis[now.p]) continue;
		vis[now.p]=true;
		for (int i=0;i<vct[now.p].size();++i){
			Edge E=vct[now.p][i];
			if (Dis[E.v]>Dis[now.p]+E.w)
			{Dis[E.v]=Dis[now.p]+E.w;pq.push({E.v,Dis[E.v]});}
		}
	} return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;++i) cin >> w[i];
	int k,a,t;
	for (int i=1;i<=n;++i){
		cin >> k;
		for (int j=1;j<=k;++j){
			cin >> a >> t;
			vct[i].push_back({n+a,t});
			vct[n+a].push_back({i,t});
		}
	} while (q--){
		cin >> x >> y;
		x+=n;y+=n;
		if (mp[x][y]>0){cout << mp[x][y] << '\n';continue;}
		Dijk();mp[x][y]=mp[y][x]=Dis[y]+w[x-n]+w[y-n];
		cout << Dis[y]+w[x-n]+w[y-n] << '\n';
	} return 0;
} //AFO.
