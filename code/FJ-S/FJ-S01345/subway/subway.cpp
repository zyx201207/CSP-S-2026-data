#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2015],ans[2015][2015],p[2015][3];
vector<pair<int,int> >e[2015];
struct node{
	int id,dist;
	bool operator<(const node &k)const{
		return dist>k.dist;
	}
};
bool vis[2015];
void dij(int s){
	for(int i=1;i<=m;i++)vis[i]=0;
	priority_queue<node>q;
	q.push({s,0});
	ans[s][s]=0;
	while(!q.empty()){
		int u=q.top().id,dis=q.top().dist;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(pair<int,int> tto : e[u]){
			int v=tto.first,w=tto.second;
			if(ans[s][v]>ans[s][u]+w){
				ans[s][v]=ans[s][u]+w;
				q.push({v,ans[s][v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)ans[i][j]=1e15;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		cin>>p[j][0]>>p[j][1];
		for(int j=1;j<=k;j++)
		for(int o=j+1;o<=k;o++){
			int u=p[j][0],v=p[o][0],w=p[j][1]+p[o][1];
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
	for(int i=1;i<=m;i++)dij(i);
	while(q){
		q--;
		int u,v;
		cin>>u>>v;
		cout<<ans[u][v]+a[u]+a[v]<<'\n';
	}
	return 0;
}
