#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M],k[N];
//int a[N][M],t[N][M];
vector<int> a[N];
vector<int> t[N];
vector<pair<int,int>> e[M];
bool vis[M];
bool ist[M];
vector<pair<int,int>> qid[M];

struct rp{
	ll sum;
	int now;
	int idx;
	bool operator<(const rp& a)const{
		return sum>a.sum;
	}
};

void dij(int s,int z){
	memset(vis,0,sizeof(vis));
//	for(int i=1;i<=n;i++) qid[i].clear();
	vector<ll> dis(m+1,1e18);
	priority_queue<rp> q;
	dis[s]=0;
//	for(pair<int,int> i:qid[s]) cout<<i.first<<'\n';
//		cout<<"1-1\n"<<'-'<<s;
	q.push({dis[s],s,qid[s].front().first});
	while(!q.empty()){
		int u=q.top().now;
		int nid=q.top().idx;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<(int)e[u].size();i++){
			int v=e[u][i].first;
			int idx=e[u][i].second;
			if(nid!=idx){
				ist[u]=1;
				ll w=t[nid][u]+t[idx][u];
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					if(!vis[v]) q.push({dis[v],v,idx});
				}
			}else{
				dis[v]=dis[u];
				if(!vis[v]) q.push({dis[v],v,idx});
			}
		}
	}
	ll res=0,ress=0,resz=0;
	ress=w[s]+t[qid[s][0].first][qid[s][0].second];
	resz=w[z]+t[qid[z][0].first][qid[z][0].second];
	res=dis[z]+ress+resz;
	cout<<res<<'\n';
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			int _a,_t;cin>>_a>>_t;
			a[i].push_back(_a);
			t[i].push_back(_t);
			qid[a[i][j]].push_back({i,j});
//			if(a[i][j]==1) for(pair<int,int> i:qid[1]) cout<<i.first<<'\n';
			if(j>0){
				e[a[i][j]].push_back({a[i][j-1],i});
				e[a[i][j-1]].push_back({a[i][j],i});
			}
		}
	}
	while(q--){
		int x, y;
		cin>>x>>y;
		dij(x,y);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
