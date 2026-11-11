#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
vector<pii> e[500010];
unsigned long long n,m,c,d,p,w[500010],a[500010],t[500010],dis[500010],vis[500010];
void f(int st,int en){
	memset(dis,0x3f,sizeof dis);
	dis[st]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({dis[st],st});
	while(q.size()){
		int u=q.top().second; q.pop();
		for(auto nt:e[u]){
			int w=nt.second,
				v=nt.first;
			if(vis[v]) continue;
			vis[v]=1;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//std::sync_stdio(0);
//	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int jj=j;jj<=k;jj++){
				e[a[j]].push_back({a[jj],t[jj]+t[j]});
				e[a[jj]].push_back({a[j],t[jj]+t[j]}); 
			}
		}
	}
	while(p--){
		int st,en;
		long long ans=0;
		cin>>st>>en;
		ans=w[st]+w[en];
		memset(vis,0,sizeof vis);
		f(st,en);
		if(dis[en]>=0x3f3f3f3f) cout<<-1;
		else cout<<ans+dis[en]<<endl;
	}
	return 0;
}
