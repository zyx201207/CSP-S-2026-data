#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int N = 505;

int c;//测试点编号
int n;//地铁线路数
int m;//地铁站数
int d;//每个地铁站最多被几条线路经过
int q;//出行计划数
int s;
int e;
int t[N][N];// 第i条线路在j号地铁站走到站点的时间 t[0][i]是地铁口走到站点的时间 
vector<pair<int,int> > g[N]; // g[i][j].first ，g[i][j].second 为 g[i][j].first 线路 可以从 i 到 g[i][j].second 

int ans = INF;

int find(){
	
	priority_queue<pair<int, pair<int,int> > > q;//目前花费first。在second.first号线，second.second站 
	q.push({0,{0,s}});
	
	while(q.size()){
		int cost = q.top().first;
		int line = q.top().second.first;
		int u = q.top().second.second;
		q.pop();
		
		if(u == e){
			ans = min(ans, cost);
			continue;
		}
		
		rep(i,0,g[u].size() - 1, 1){
			int toline = g[u][i].first;
			int v = g[u][i].second;
			printf("Line %d station %d  --> Line %d station %d \n\t cost %d\n", line, u, toline, v, cost);
			
			if(toline == line){
				q.push({cost, {toline, v}});
//				printf("S: Line %d station %d  --> Line %d station %d \n\t cost %d\n", line, u, toline, v, cost);
			}
			else {
				int newcost = cost + t[line][v] + t[toline][v];
				q.push({newcost, {toline, v}});
//				printf("T: Line %d station %d  --> Line %d station %d \n\t cost %d\n", line, u, toline, v, newcost);
			}
		}
	}
	
	return -1;
}


void solve(){
	cin >> s >> e;
	find();
	cout << ans << endl;
}

int main(){

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> n >> m >> d >> q;
	rep(i,1,m,1) cin >> t[0][i];
	rep(i,1,n,1) {//line
		int k;
		int last;
		int to = -1;
		cin >> k;
		rep(j,1,k,1){
			last = to;
			cin >> to;
			cin >> t[i][to];
			printf("%d %d\n",to, t[i][to]);
			g[0].push_back({i, to});
			if(j == 1) continue;
			g[last].push_back({i, to});
		}
	}
	
	rep(i,0,n,1){//Line
		rep(j,1,m,1){//from station
			for(int k = 0; k < g[j].size(); k ++){
				int toline = g[j][k].first;
				int tostation = g[j][k].second;
				printf("%d : %d -> %d : %d\n",i,j,toline,tostation);
			}
		}
	}
	
	while(q--) solve();


	return 0;
}








