#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q,w[500005],sum[500005],be[500005],k[505],l[500005],tot,a[500005],vis[500005],t[500005],dis[600005];
struct node{
	int p,l;
}rk[600005];
vector<pair<int,int> >e[600005];
map<pair<int,int>,int>mp;
void dj(int s){
	priority_queue<pair<int,int> >q;
	for(int i=1;i<=tot;i++)	dis[i]=1e18,vis[i]=0;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(auto p:e[u]){
			int v=p.first,w=p.second;
			if(v==0)	continue;
			dis[v]=min(dis[v],dis[u]+w);
			q.push({-dis[v],v});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=8){
		for(int i=1;i<=m;i++)	cin>>w[i];
		tot=m;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++)	a[j]=t[j]=0;
			for(int j=1;j<=k[i];j++){
				cin>>a[j]>>t[j];
				mp[{a[j],i}]=++tot;
				rk[tot]={a[j],i};
				e[a[j]].push_back({tot,t[j]});
				e[tot].push_back({a[j],t[j]});
				e[tot].push_back({mp[{a[j-1],i}],0});
				e[mp[{a[j-1],i}]].push_back({tot,0});
			}
		}
//		for(int i=1;i<=tot;i++){
//			for(auto j:e[i])	cout<<i<<" "<<j.first<<" "<<j.second<<endl;
//		}
//		cout<<endl;
		while(q--){
			int x,y;
			cin>>x>>y;
			dj(x);
//			for(int i=1;i<=tot;i++)	cout<<dis[i]<<" ";
//			cout<<endl;
			cout<<dis[y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}

