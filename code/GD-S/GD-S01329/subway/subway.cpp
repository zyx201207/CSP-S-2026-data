#include<bits/stdc++.h>
#include<cstdio>
typedef long long ll;
using namespace std;
ll w[500005];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ll c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	vector<ll>v[3];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		ll k;cin>>k;
		
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			v[i].push_back(a);
			v[i].push_back(t);
		}
	}
	while(q--){
		ll x,y;cin>>x>>y;ll ans=0;
	//	ans+=w[x]+w[y];
		queue<ll>q;
		q.push(x);
		//ll ans=0;
	
		ll vis[500005];
		for(int i=1;i<=500000;i++)vis[i]=-1;
			vis[x]=w[x];
		while(q.size()){
			ll u=q.front();q.pop();
			for(auto i:u){
				if(vis[i]!=-1)continue;
				q.push(i);
				vis[i]=v[i][1]+vis[u];
			}
		}
		cout<<vis[y]+w[y];
	}
	return 0;
} 
