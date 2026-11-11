#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define sc second
#define pb push_back
using namespace std;

int c,n,m,d,q,tot;
vector<pll>g[510007*3];
ll dis[510007*3];

ll dji(int x,int y){
	for(int i=1;i<=m*2+tot;++i)dis[i]=1e18;
	priority_queue<pll,vector<pll>,greater<>>q;
	q.push({0,x});
	dis[x]=0;
	while(!q.empty()){
		pll cur=q.top();
		int u=cur.sc;
		ll w=cur.fi;
		q.pop();
		if(u==y)return w;
		if(w>dis[u])continue;
		for(pll p:g[u]){
			int v=p.fi;
			ll add=p.sc;
			if(dis[v]>w+add){
				dis[v]=w+add;
				q.push({w+add,v});
			}
		}
	}
	return 1e18;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	tot=2*m;
	for(int i=1;i<=m;++i){
		ll w;
		cin>>w;
		g[i].pb({i+m,w});
		g[i+m].pb({i,w});
	}
	for(int i=1;i<=n;++i){
		int tmp,k;
		ll w;
		cin>>tmp;
		int la=-1;
		for(int j=1;j<=tmp;++j){
			cin>>k>>w;
			tot++;
			g[tot].pb({k+m,w});
			g[k+m].pb({tot,w});
			if(la!=-1){
				g[la].pb({tot,0});
				g[tot].pb({la,0});
			}
			la=tot;
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<dji(x,y)<<'\n';
	}
	return 0;
} 
