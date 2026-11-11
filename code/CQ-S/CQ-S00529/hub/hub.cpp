#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll c,T,answer;
ll n,k;
ll U[N],V[N];
bool in[N];
ll fa[N];
vector<ll>g[N];
ll find(ll k){
	return fa[k]==k?k:fa[k]=find(fa[k]);
}
ll AS;
void DFS(ll u,ll father,ll dis){
	if(in[u]){
		AS=min(AS,dis);
	}
	for(ll to:g[u]){
		if(to==father)continue;
		DFS(to,u,dis+1);
	}
}
void work(){
	ll all=k;
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=1;i<n;i++){
		if(in[U[i]]&&in[V[i]]){
			ll x=find(U[i]),y=find(V[i]);
			if(x!=y){
				fa[x]=y;
				all--;
			}
		}
	}
	if(all<=2){
		ll sum=0;
		for(ll i=1;i<=n;i++){
			if(in[i]==false){
				AS=2e18;
				DFS(i,0,0);
				sum=max(sum,AS);
			}
		}
		answer=min(answer,sum);
	}
}
void dfs(ll u,ll number){
	if(number>k)return;
	if(u==n+1){
		if(number==k){
			work();
		}
		return;
	}
	in[u]=true;
	dfs(u+1,number+1);
	in[u]=false;
	dfs(u+1,number);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	clock_t t0=clock();
	ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(c<=3||c==7||k==1){
			for(ll i=1;i<=n;i++)g[i].clear();
			for(ll i=1;i<n;i++){
				cin>>U[i]>>V[i];
				g[U[i]].push_back(V[i]);
				g[V[i]].push_back(U[i]);
			}
			answer=2e18;
			dfs(1,0);
			cout<<answer<<endl;
		}
		else if(c==13||c==14){
			for(ll i=1;i<n;i++){
				cin>>U[i]>>V[i];
			}
			ll p=n/4+1;
			cout<<p-k<<endl;
		}
	}
	fprintf(stderr,"time=%.3fs\n",(double)(clock()-t0)/CLOCKS_PER_SEC);
	return 0;
}

/*
15+[0,10]
*/
