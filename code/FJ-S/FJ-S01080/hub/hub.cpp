#include<bits/stdc++.h>
using namespace std;
const int N=11;
int c,t;
int n,k;
bool e[N][N];
int fa[N];

int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>c>>t;
	while(t--){
		memset(e,0,sizeof(e));
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
			e[u][v]=e[v][u]=1;
		}
		int r=100;
		for(int i=0;i<(1<<n);i++){
			int nowr=0;
			int cnt=0;
			for(int j=1;j<(1<<n);j<<=1){
				if(i&j) cnt++;
			}
			if(cnt!=k) continue;
			vector<int> use;
			for(int j=1;j<=n;j++){
				fa[j]=j;
			}
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					use.push_back(j);
				}
			}
			for(auto j:use){
				for(auto x:use){
					if(find(j)!=find(x)&&e[j][x]){
						fa[fa[j]]=fa[x];
					}
				}
			}
			bool vis[n+1]={0};
			cnt=0;
			for(auto j:use){
				if(!vis[find(j)]){
					cnt++;
					vis[find(j)]=1;
				}
			}
			if(cnt>2) continue;
			int dis[n+1];
			bool inq[n+1]={0};
			for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
			priority_queue<pair<int,int>> q;
			for(auto j:use){
				dis[j]=0;
				q.push({0,j});
				inq[j]=1;
			}
			while(!q.empty()){
				auto e1=q.top();
				q.pop();
				int d=e1.first,u=e1.second;
				if(!inq[u]) continue;
				inq[u]=0;
				for(int v=1;v<=n;v++){
					if(!e[u][v]) continue;
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push({dis[v],v});
						inq[v]=1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				nowr=max(nowr,dis[i]);
			}
			r=min(r,nowr);
		}
		cout<<r<<"\n";
	}

	return 0;
}

