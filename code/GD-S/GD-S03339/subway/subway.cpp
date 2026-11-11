#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=1e5+1;
int c,n,m,d,T,st,en;
ll ex_w[N],w[N][501],dis[501][501],a[N][501],g[501][501],ans;
bool vis[501];
vector<int>line[N];
struct Graph{
	int to;
	long long w;
	bool operator <(const Graph &x)const{
		return x.w<w;
	}
};
priority_queue<Graph>q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>ex_w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,to,v;j<=k;j++){
			cin>>to>>v;
			a[to][i]=v,w[to][i]=ex_w[to]+v,line[to].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=g[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			if(!a[i][j]) continue;
			for(int k=j+1;k<=n;k++){
				if(!a[i][k]) continue;
				g[j][k]=g[k][j]=min(g[j][k],a[i][j]+a[i][k]);
			}
		}
	}
	for(st=1;st<=n;st++){
		memset(vis,0,sizeof(vis));
		q.push({st,0});
		dis[st][st]=0;
		while(!q.empty()){
			Graph k=q.top();
			q.pop();
			if(vis[k.to]) continue;
			vis[k.to]=1;
			for(int j=1;j<=n;j++){
				if(g[k.to][j]==1e18) continue;
				if(dis[st][k.to]+g[k.to][j]<dis[st][j]){
					dis[st][j]=dis[st][k.to]+g[k.to][j];
					q.push({j,dis[st][j]});
				}
			}
		}
	}
	while(T--){
		ans=1e18;
		cin>>st>>en;
		for(int i:line[st]){
			for(int j:line[en]){
				ans=min(ans,dis[i][j]+w[st][i]+w[en][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
