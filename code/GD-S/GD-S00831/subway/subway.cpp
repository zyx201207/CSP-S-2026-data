#include<bits/stdc++.h>
using namespace std;
const int N = 550;
const int M = 5e5+50;
int c, n, m, d, q, w[N], k[N], a[N][N], t[N][N], dis[N][N][N], ans[N][N];
bool vis[N][N];
struct edge{
	int v, l;
};
vector<edge> e[M];
vector<int> ll[N];
struct ped{
	int u, t, l;
	friend bool operator<(const ped & A, const ped & B){
		return A.t > B.t;
	}
};
void dij(int s){
	for(int i=0;i<=m;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=0;
	priority_queue<ped>q;
	for(int v:ll[s]){
		q.push({s, t[v][s]+w[s], v});
		dis[s][s][v] = w[s] + t[v][s];
	}
	ans[s][s] = w[s];
	while(q.size()){
		int u = q.top().u;
		int l = q.top().l;
		q.pop();
		if(vis[u][l])continue;
		vis[u][l]=1;
//		cout << u<<" "<< l << endl;////////////////////////////////////////////////////////////////////////////
		for(auto ed : e[u]){
			int v = ed.v;
			int ll = ed.l;
//			if(dis[s][v][l] == min(dis[s][v][l], dis[s][u][l])){///////////////////////////////////////////////
//				cout <<"A"<< s<<" "<<v<<" "<<l<<endl;//////////////////////////////////////////////////////////
//			}//////////////////////////////////////////////////////////////////////////////////////////////////
			dis[s][v][l] = min(dis[s][v][l], dis[s][u][l]);
			if(l != ll){		
//				if(dis[s][v][ll] == min(dis[s][v][ll], dis[s][v][l]+t[l][v]+t[ll][v])){////////////////////////
//					cout << "B" << s <<" "<<v<<" "<<l<<"->"<<ll<<" "<<t[l][v]<<" "<<t[ll][v]<<endl;////////////
//				}//////////////////////////////////////////////////////////////////////////////////////////////
				dis[s][v][ll] = min(dis[s][v][ll], dis[s][v][l]+t[l][v]+t[ll][v]);
			}
			else{
				dis[s][v][ll] = dis[s][v][l];
			}
			ans[s][v] = min(ans[s][v], dis[s][v][l] + w[v] + t[l][v]);
			q.push({v, dis[s][v][ll], ll});
		}
	}
}
int solve(int x, int y){
	return ans[x][y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin >> a[i][j] >> x;
			ll[a[i][j]].push_back(i);
			t[i][a[i][j]] = x;
			if(j > 1){
				e[a[i][j]].push_back({a[i][j-1], i});
				e[a[i][j-1]].push_back({a[i][j], i});
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans[i][j] = 0x3f3f3f3f;
			ans[j][i] = 0x3f3f3f3f;
			for(int k=1;k<=m ;k++){
				dis[i][j][k] = 0x3f3f3f3f;
				dis[j][i][k] = 0x3f3f3f3f;
			}
		}
	}
	for(int i=1;i<=m;i++){
		dij(i);
	}
	for(int i=1;i<=q;i++){
		int x, y;
		cin >> x>> y;
		cout << solve(x, y)<<endl;
	}
	return 0;
}
