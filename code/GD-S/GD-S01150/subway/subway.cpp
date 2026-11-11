#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],dis[M];
int gv(int x,int y){
	return x*M+y;
}
pair<int,int> gt(int z){
	return make_pair(z/M,z%M);
}
vector<pair<int,int>> e[N*M];
vector<int> l[M];
bool vis[N*M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			l[a[i][j]].push_back(i);
			if(j==1) continue;
			int u=gv(i,a[i][j]),v=gv(i,a[i][j-1]);
			e[u].emplace_back(v,0);
			e[v].emplace_back(u,0);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<l[i].size();j++){
			int u=gv(l[i][j],i),v=gv(l[i][j-1],i);
			e[u].emplace_back(v,t[l[i][j]][i]+t[l[i][j-1]][i]);
			e[v].emplace_back(u,t[l[i][j]][i]+t[l[i][j-1]][i]);
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		queue<int> q;
		q.push(gv(1,st));
		vis[st]=1;
		while(!q.empty()){
			int ns=q.front();
			q.pop();
			for(auto [v,w]:e[ns]){
				if(vis[v]) continue;
				vis[v]=1;
				dis[v]=dis[ns]+w;
				q.push(v);
			}
		}
		cout<<dis[ed]<<"\n";
	}
	return 0;
}
