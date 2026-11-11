#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+5;
ll c,t;
ll n,d,x[N],ans;
vector<ll> e[N];

ll bfs(ll s){
	ll dis[N],cnt=0,vis[N];
	memset(vis,1,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	queue<ll> q;
	q.push(s);
	dis[s]=0;
	while (!q.empty()){
		ll u=q.front();
		q.pop();
		for(auto v:e[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
			if(dis[v]==dis[u]+1)
				vis[v]++;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]>=2){
			ll sum=vis[i];
			cnt+=(sum*(sum-1))/2;
		}
	}
	return cnt;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
		ans=bfs(1);
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/


