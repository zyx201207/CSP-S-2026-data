#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node {
	int a,t;
};
int c,n,m,d,q;
int w[500010];
bool vis[500010];
int di[500010];
vector<node> way[510];
vector<int>  cnt[500010];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin >>w[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin >>k;
		int a,t;
		for(int j=1; j<=k; j++) {
			cin >>a>>t;
			way[i].push_back({a,t});
			cnt[a].push_back(i);
		}
	}
//	for(int i=0; i<way[2].size(); i++) {
//		cout <<way[2][i].a<<" "<<way[2][i].t<<endl;
//	}
//	cout <<endl;
	while(q--) {
		int x,y;
		cin >>x>>y;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//first是时间,second是当前的站厅
		fill(vis,vis+1+m,0);
		fill(di,di+1+m,INT_MAX);//vis是“是否已经确定”，d是x~i的最短路径长度，当vis[i]！=1时可以被当作某次的开始节点然后就vis[i]=1
		pq.push({w[x]+w[y],x});//已经加上了前后从地铁站口到站厅和站厅到地铁站口的时间
		while(!pq.empty()) {
			pair<int,int> now=pq.top();//first是时间,second是当前的站厅
			pq.pop();
			if(vis[now.second]||di[now.second]<now.first)continue;
			vis[now.second]=1;
			di[now.second]=now.first;
			if(now.second==y)break;
			for(int i=0; i<cnt[now.second].size(); i++) { //经过now.second的有 cnt[now.second].size()条线路
//				cout <<cnt[now.second][i]<<" "<<now.second<<" ";
				for(int j=0; j<way[cnt[now.second][i]].size(); j++) { //经过这条线路的有 way[cnt[now.second][i]].size()个地铁站台
					int to=way[cnt[now.second][i]][j].a;
//					cout <<j<<" "<<way[cnt[now.second][i]][j].t<<endl;
//					cout <<to<<" "<<way[cnt[now.second][i]][j].t+now.first+way[cnt[now.second][i]][now.second-1].t<<" "<<di[to]<<endl;//
					if(!vis[to]&&di[to]>now.first+way[cnt[now.second][i]][j].t+way[cnt[now.second][i]][now.second-1].t) {//
//						cout <<to<<"kk"<<endl;
						di[to]=now.first+way[cnt[now.second][i]][j].t+way[cnt[now.second][i]][now.second-1].t;
						//这个站厅没被确定且去的时间比我原来到这里的时间短
						pq.push({now.first+way[cnt[now.second][i]][j].t+way[cnt[now.second][i]][now.second-1].t,to});
					}
				}
			}
		}
		cout <<di[y]<<endl;
	}
	return 0;
}
