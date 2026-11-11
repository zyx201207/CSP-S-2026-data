#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+510;
int c,n,m,d,q,w[N],ki,aij,tij,x,y;
vector<pair<int,int>> vec[N*2];
int dis[N],vis[N],que[N],ql,qr;
void bfs(int st){
	for(int i=1;i<=m+n;i++){
		dis[i]=1e18,vis[i]=0;
	}
	dis[st]=0,vis[st]=1;
	ql=qr=1,que[1]=st;
	while(ql<=qr){
		int u=que[ql];
		ql++;
		for(pair<int,int> i:vec[u]){
			int v=i.first,w=i.second;
			if(vis[v]) continue;
			vis[v]=1;
			dis[v]=dis[u]+w;
			qr++;
			que[qr]=v;
		}
	}
}
int mdis[1024][1024];
void mdijkstra(int st){
	for(int i=1;i<=m+n;i++){
		mdis[st][i]=1e18,vis[i]=0;
	}
	mdis[st][st]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,st});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pair<int,int> i:vec[u]){
			int v=i.first,w=i.second;
			if(mdis[st][v]>mdis[st][u]+w){
				mdis[st][v]=mdis[st][u]+w;
				pq.push({-mdis[st][v],v});
			}
		}
	}	
}
vector<pair<int,int>> conme[N];
int minhuan;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>aij>>tij;
			vec[aij].push_back({m+i,tij});
			vec[m+i].push_back({aij,tij});
			conme[aij].push_back({i,tij});
		}
	}
	if(c<=11){
		for(int i=1;i<=m+n;i++){
			mdijkstra(i);
		}
		while(q--){
			cin>>x>>y;
			cout<<mdis[x][y]+w[x]+w[y]<<endl;
		}
		return 0;
	}
	else if(c<=19){
		while(q--){
			cin>>x>>y;
			bfs(x);
			cout<<dis[y]+w[x]+w[y]<<endl;
		}
		return 0;
	}
	else if(n==1){
		while(q--){
			cin>>x>>y;
			cout<<w[x]+w[y]+conme[x][0].second+conme[y][0].second<<endl;
		}
		return 0;
	}
	minhuan=1e18;
	for(int i=1;i<=m;i++){
		if(conme[i].size()==2){
			minhuan=min(minhuan,conme[i][0].second+conme[i][1].second);
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=1e18;
		for(pair<int,int> weix:conme[x]){
			int bianx=weix.first,shix=weix.second;
			for(pair<int,int> weiy:conme[y]){
				int biany=weiy.first,shiy=weiy.second;
				if(bianx==biany) ans=min(ans,shix+shiy);
				else{
					ans=min(ans,shix+shiy+minhuan);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
/*

100 


*/
