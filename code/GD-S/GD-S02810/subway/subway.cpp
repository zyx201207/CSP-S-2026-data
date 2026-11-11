#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 505
#define maxm 1000005
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m;
int a[maxn][20005],t[maxn][20005];
int w[maxn],p,q,dr;
bool vis[maxn][20005];
vector<pair<int,int>>G[maxm]; 
int dis[maxn][20005];
int x[maxm],y[maxm];
struct Info{
	int d,id,v;
	bool operator >(const Info&o)const{
		return d>o.d;
	}
};
//struct qus{
//	int x,y;
//	bool operator <(const qus&o)const{
//		return x<o.x;
//	}
//};
vector<int>qs[maxm];
void dij(int s){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			dis[i][j]=inf;
			vis[i][j]=false;
		} 
	}
	priority_queue<Info,vector<Info>,greater<Info> >q;
	for(auto r:G[s]){
		q.push({t[r.second][s],r.second,s});
		dis[r.second][s]=t[r.second][s];
	} 
	while(!q.empty()){
		int u=q.top().v,lt=q.top().id;
		q.pop();
		if(vis[lt][u])continue;
		vis[lt][u]=true;
		for(auto x:G[u]){
			int v=x.first,id=x.second;
			if(id==lt&&dis[id][v]>dis[lt][u]){
				dis[id][v]=dis[lt][u];
				q.push({dis[id][v],id,v});
//				cout << u << " " << lt << " " << v << " " << id << " " << dis[id][v] << '\n';
			}else if(dis[id][v]>dis[lt][u]+t[lt][u]+t[id][u]){
				dis[id][v]=dis[lt][u]+t[lt][u]+t[id][u];
//				cout << u << " " << lt << " " << v << " " << id << " " << dis[id][v] << '\n';
				q.push({dis[id][v],id,v});
			}
		}
	}
}
int pr(int x,int y){
	return x*1e8+y;
}
unordered_map<int,int>mp; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> p >> n >> m >> dr >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}

	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		a[i][0]=k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][a[i][j]];
		}
		for(int j = 1;j<k;j++){
			G[a[i][j]].push_back({a[i][j+1],i});
			G[a[i][j+1]].push_back({a[i][j],i});
		}
	}
	if(m<=400){
		while(q--){
			int x,y;
			cin >> x >> y;
			int mi=inf;
			dij(x);
			for(int i = 1;i <= n;i++){
				mi=min(mi,dis[i][y]+t[i][y]);
			}
			cout << mi+w[x]+w[y] << '\n';
		}
	}else{
		for(int i = 1;i <= q;i++){
			cin >> x[i] >> y[i];
			qs[x[i]].push_back(y[i]);
		}
		for(int i = 1;i <= m;i++){
			if(qs[i].size()>0){
				dij(i);
				for(auto u:qs[i]){
					for(int j = 1;j <= n;j++){
						mp[pr(i,u)]=max(mp[pr(i,u)],inf-(dis[j][u]+t[j][u]+w[i]+w[u]));
					}
				}
			}
		}
		for(int i = 1;i <= q;i++){
			cout << inf-mp[pr(x[i],y[i])] << '\n';
		}
	}
	
	
	
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
