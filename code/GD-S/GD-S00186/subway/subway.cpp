#include<bits/stdc++.h>
using namespace std;
long long w[500005];
vector<pair<int,int> >a[500005];
vector<pair<int,int> >xian[505];
bool vis[500005];
long long dis[500005];
int f[500005];
vector<int>e[500005];
int dian[500005];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,qq;
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int e,t;
			cin>>e>>t;
			a[e].push_back({i,t});
			xian[i].push_back({e,t});
		}
	}
	if(c<=6){
		while(qq--){
			int x,y;
			cin>>x>>y;
			memset(dis,127,sizeof(dis));
			memset(vis,0,sizeof(vis));
			queue<pair<int,int> >q;
			q.push({x,0});
			dis[x]=0;
			vis[x]=1;
			bool fd=0;
			while(!q.empty()){
				int u=q.front().first;
				int d=q.front().second;
				q.pop();
				if(dis[u]!=d)continue;
				for(pair<int,int> p:a[u]){
					int xi=p.first;
					int tim=p.second;
					for(pair<int,int>pp:xian[xi]){
						int v=pp.first;
						if(u==v)continue;
						if(!vis[v]||dis[v]>dis[u]+tim+pp.second){
							if(dis[v]>dis[u]+tim+pp.second)dis[v]=dis[u]+pp.second+tim;
//							cout<<u<<' '<<v<<' '<<d+tim+pp.second<<'\n';
							vis[v]=true;
							q.push({v,d+tim+pp.second});
						}
					}
				}
			}
			cout<<dis[y]+w[x]+w[y]<<'\n';
//			for(int i=1;i<=m;i++){
//				cout<<dis[i]<<' ';
//			}
		}	
	}
	else if(c<=11){
		vector<pair<int,int> >e[10005];
		for(int i=1;i<=n;i++){
			if(xian[i].size()>1){
				int u=xian[i][1].first;
				int v=xian[i][0].first;
				long long va=xian[i][0].second+xian[i][1].second;
				e[u].push_back({v,va});
				e[v].push_back({u,va});
			}
		}
		while(qq--){
			memset(vis,0,sizeof(vis));
			memset(dis,127,sizeof(dis));
			queue<pair<int,int> >q;
			int x,y;
			cin>>x>>y;
			q.push({x,0});
			vis[x]=1;
			while(!q.empty()){
				int u=q.front().first;
				int ti=q.front().second;
				q.pop();
				for(pair<int,long long>p:e[u]){
					int v=p.first;
					int ww=p.second;
					if(!vis[v]||dis[v]>dis[u]+ww){
						dis[v]=min(dis[v],dis[u]+ww);
						vis[v]=1;
						q.push({v,dis[u]+ww});
					}
				}
			}
			cout<<dis[y]+w[x]+w[y]<<'\n';
		}
	}
	else if(c<=19){
		int T=xian[1][0].second;
		memset(vis,0,sizeof(vis));
		
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		
		for(int i=1;i<=n;i++){
			for(pair<int,int> p:xian[i]){
				int v=p.first;
				if(f[v]==v){
					f[v]=xian[i][0].first;
					dian[v]=i;
				}
				else{
					int xx=find(v);
					e[xx].push_back(i);
				}
			}
		}
		while(qq--){
			int x,y;
			cin>>x>>y;
			int idxx=dian[x];
			int idyy=dian[y];
			if(idxx==idyy){
				cout<<2*T<<'\n';
			}
			else{
				queue<pair<int,int> >q;
				q.push({idxx,0});
				vis[idxx]=1;
				bool fd=0;
				while(!q.empty()){
					int u=q.front().first;
					int ww=q.front().second;
					for(int v:e[u]){
						if(vis[v])continue;
						if(v==idyy){
							fd=1;
							cout<<2*(ww+1)*T<<'\n';
							break;
						}
						vis[v]=1;
						q.push({v,ww+1});
					}
					if(fd)break;
				}
			}
		}
	}
}
