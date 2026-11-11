#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,C,T,ccc;
ll dis[5100],vis[5100],c[5100],a[5100];
vector<ll>g[5100];
ll bfs(ll u){
	ll ans=0;
	memset(c,0,sizeof c);
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<ll>q;
	dis[u]=0;
	vis[u]=1;
	q.push(u);
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		for(int i=0;i<ll(g[x].size());i++){
			if(vis[i]!=2){
				if(dis[i]==dis[x]+1)c[i]++;
				else{
					dis[i]=dis[x]+1;
					q.push(i);
					vis[i]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]==1)ans++;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		ll ccc=0;
		for(int i=1;i<=n;i++){
			ccc+=bfs(i);
		}
		cout<<ccc<<endl;
	}
	return 0;
}
