#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c, n, m, d, q,w[555555],a[555][555],ans,dp[555][555],dis[555],vis[555];
vector<pair<int,ll>>g[555];
priority_queue<pair<int,ll>,vector<pair<int,ll>>,greater<pair<int,ll>>>qq;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int q1;
		cin>>q1;
		vector<int>v1;
		v1.push_back(0);
		for(int j=1;j<=q1;j++){
			ll u,t;
			cin>>u>>t;
			v1.push_back(u);
			a[u][i]=t;//在u站台到i号线的时间t 
			//cout<<t<<"!!!!!!!";
		}
		for(int j=1;j<v1.size();j++){
			int u=v1[j];
			for(int k=1;k<v1.size();k++){
				int v=v1[k];
				if(u==v)continue;
				g[u].push_back({v,a[u][i]+a[v][i]});
				//cout<<a[j][i]+a[k][i]<<"!!!!!!!";
				//g[v].push_back({u,a[u][i]+a[v][i]});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[x]=0;
		qq.push({0,x});
		while(!qq.empty()){
			int u=qq.top().second;
			qq.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int i=0;i<g[u].size();i++){
				int v=g[u][i].first;
				ll w=g[u][i].second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					qq.push({dis[v],v});
				}
				//if(vis[y])break;
			}
			//if(vis[y])break;
		}
		ans+=dis[y];
		cout<<ans<<endl;
	}
	cout<<endl<<endl;
	for(int i=1;i<=m;i++){
		//cout<<i<<":";
		//for(int j=0;j<g[i].size();j++)cout<<g[i][j].first<<" "<<g[i][j].second<<";";
		//cout<<endl;
	}
	return 0;
} 
