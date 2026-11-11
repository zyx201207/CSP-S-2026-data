#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int M=505;
int n,m,d,qq,c;
map<pair<int,int>,int> mp;
vector<pair<int,int> > v[M];
vector<pair<int,int> > g[N];
int a[N];
int dis[N][N];
int vis[N][N];
void bfs(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({x,a[x]});
	dis[x][x]=a[x];
	while(!q.empty()){
		pair<int,int> r=q.top();
		q.pop();
		for(auto i:g[r.first])
			if(dis[x][r.first]+i.second<dis[x][i.first]){
				dis[x][i.first]=dis[x][r.first]+i.second;
				//cout<<"ok"<<endl;
				q.push({i.first,dis[x][i.first]});
			}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,c;
			cin>>x>>c;
			v[i].push_back({x,c});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)v[i].size();j++)
			for(int k=j+1;k<(int)v[i].size();k++){
				//fg[v[j].first].push_back({v[k].first,v[j].second+v[k].second});
				if(mp.count({v[i][j].first,v[i][k].first})) mp[{v[i][j].first,v[i][k].first}]=min(v[i][j].second+v[i][k].second,mp[{v[i][j].first,v[i][k].first}]),mp[{v[i][k].first,v[i][j].first}]=min(v[i][j].second+v[i][k].second,mp[{v[i][k].first,v[i][j].first}]);
				else mp[{v[i][j].first,v[i][k].first}]=v[i][j].second+v[i][k].second,mp[{v[i][k].first,v[i][j].first}]=v[i][j].second+v[i][k].second;
			}
	}
	for(auto i:mp) g[i.first.first].push_back({i.first.second,i.second});
	memset(dis,0x3f,sizeof(dis));
//	for(int i=1;i<=m;i++){
//		cout<<i<<endl;
//		for(auto j:g[i]) cout<<j.first<<" "<<j.second<<endl;
//		//cout<<endl;
//	}
	while(qq--){
		int s,t;
		cin>>s>>t;
		if(dis[s][t]>1e9) bfs(s);
		cout<<dis[s][t]+a[t]<<endl;
	}
	//for(int i=1;i<=m;i++) sort()
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
