#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
const int N=5e5+10;
vector<pair<int,int> >G[2*N];//1~n将地铁视为节点,n+1~n+m视为站台 
int w[N];
map<int,map<int,int> >dis;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int station,T;
			cin>>station>>T;
			G[i].push_back({n+station,T});
			G[n+station].push_back({i,T});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:G[i+n]){
			for(auto v:G[i+n]){
				if(u.first!=v.first){
					G[u.first].push_back({v.first,u.second+v.second});
					G[v.first].push_back({u.first,u.second+v.second});
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(dis[x][y]!=0){cout<<dis[x][y]<<'\n';continue;}
		int ans=w[x]+w[y];
		bool vis[N]={};
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
		pq.push({x+n,0});
		while(!pq.empty()){
			auto now=pq.top();
			pq.pop();
			if(vis[now.first]==1)continue;
			vis[now.first]=1;
			int pos=now.first,dis=now.second;
			if(pos==y+n){
				ans+=dis;
				break;
			}
			for(auto v:G[pos]){
				if(vis[v.first]==0){
					pq.push({v.first,dis+v.second});
				}
			}
		}
		dis[x][y]=dis[y][x]=ans;
		cout<<ans<<'\n';
	}
}
