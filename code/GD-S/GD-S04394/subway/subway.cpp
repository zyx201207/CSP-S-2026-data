#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,int> > g[500005];//Ç°cºóx
priority_queue<pair<long long,pair<int,int> >,vector<pair<long long,pair<int,int> > > >line;
long long dis[505][505];
long long down[500005];
long long n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c;
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>down[i]; 
	}
	for(int i=1;i<=m;i++){
		long long h;
		cin>>h;
		for(int j=0;j<h;j++){
			long long s,v;
			cin>>s>>v;
			g[s].push_back({v,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				if(dis[g[i][j].second][g[i][k].second]>g[i][j].first+g[i][k].first&&j!=k){
					dis[g[i][j].second][g[i][k].second]=min(dis[g[i][j].second][g[i][k].second],g[i][j].first+g[i][k].first);
					line.push({dis[g[i][j].second][g[i][k].second],{g[i][j].second,g[i][k].second}});	
				}
			}
		}
	}
	while(!line.empty()){
		pair<long long,pair<int,int> > nowline=line.top();
		line.pop();
		if(nowline.first<dis[nowline.second.first][nowline.second.second]){
			dis[nowline.second.first][nowline.second.second]=nowline.first;
			dis[nowline.second.second][nowline.second.first]=nowline.first;
			for(int i=1;i<=n;i++){
				if(i!=nowline.second.second&&dis[i][nowline.second.second]>dis[i][nowline.second.first]+nowline.first){
					line.push({dis[i][nowline.second.first]+nowline.first,{i,nowline.second.second}});
					dis[i][nowline.second.second]=dis[i][nowline.second.first]+nowline.first;
					dis[nowline.second.second][i]=dis[i][nowline.second.first]+nowline.first;
				}
				if(i!=nowline.second.first&&dis[i][nowline.second.first]>dis[i][nowline.second.second]+nowline.first){
					line.push({dis[i][nowline.second.first]+nowline.first,{i,nowline.second.first}});
					dis[i][nowline.second.first]>dis[i][nowline.second.second]+nowline.first;
					dis[nowline.second.first][i]>dis[i][nowline.second.second]+nowline.first;
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		int u,v;
		cin>>u>>v;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<g[u].size();j++){
			for(int k=0;k<g[v].size();k++){
				ans=min(ans,down[u]+down[v]+dis[g[u][j].second][g[v][k].second]);
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
} 
