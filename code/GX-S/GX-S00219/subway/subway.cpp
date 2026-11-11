#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
int c,n,m,d,q;
long long w[N],x[N],y[N],vis[N],dis[N],ans[N];
int a,t,k;
vector<pair<int,int>>g[N];
void diji(int s){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<(int)g[x].size();i++){
			int y=g[x][i].first,z=g[x][i].second;
			if(vis[y]==1)continue;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push({dis[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		//cout<<k<<endl;
		for(int j=1;j<=k;j++){
		    scanf("%d%d",&a,&t);
			g[i+m].push_back({a,t});
			g[a].push_back({i+m,t});
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	memset(ans,0x3f3f3f3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		diji(i+m);
//		for(int j=1;j<=n+m;j++){cout<<dis[j]<<' ';}cout<<endl;
		for(int j=1;j<=q;j++){
			ans[j]=min(ans[j],w[x[j]]+w[y[j]]+dis[x[j]]+dis[y[j]]);
		}
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
}
