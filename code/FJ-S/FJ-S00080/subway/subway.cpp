#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a,t[505][500005];
vector<int>s[500005];
vector<pair<int,int>>e[505];
long long dij(int x,int y){
	long long d[505];
	bool vis[505]={};
	memset(d,(long long)0x3f3f3f3f3f3f3f3f,sizeof(d));
	d[x]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
	q.push({0,x});
	while(!q.empty()){
		auto [abcd,u]=q.top();
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto [v,w]:e[u]){
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	return d[y];
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a;
			cin>>t[i][a];
			s[a].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j:s[i]){
			for(int o:s[i]){
				if(j==o)continue;
				int v=t[j][i]+t[o][i];
				e[j].push_back({o,v});
				e[o].push_back({j,v});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=(long long)0x3f3f3f3f3f3f3f3f;
		for(int j:s[x])
			for(int o:s[y])
				ans=min(ans,dij(j,o)+w[x]+w[y]+t[j][x]+t[o][y]);
		cout<<ans<<endl;
	}
	return 0;
}
