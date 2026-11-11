#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long 
#define R(a,b,c) for(ll a=b;a<=c;a++)
#define E(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
vector<ll> g[1000025];
ll dep2[1000025];
ll dep[1000025];
ll md[1000025];
ll dfn[1000025];
ll sz[1000025];
ll cnt=0;
ll A,B;
struct node{
	ll id,v;
};
bool operator <(node a,node b){
	return a.v<b.v;
}
int dfs(ll u,ll fa){
	dfn[u]=++cnt;
	sz[u]=1;
	md[u]=dep[u];
	for(auto v:g[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		md[u]=max(md[u],md[v]);
		sz[u]+=sz[v];
	}
	return 0;
}
int dfs2(ll u,ll fa,ll dp){
	dep2[u]=min(dep2[u],dp);
	for(auto v:g[u]){
		if(v==fa)continue;
		if(dfn[A]<=dfn[v]&&dfn[v]<=dfn[A]+sz[A]-1)continue;
		if(dfn[B]<=dfn[v]&&dfn[v]<=dfn[B]+sz[B]-1)continue;
		dfs2(v,u,dp+1);
	}
	return 0;
}
ll mad=0;
ll ffa[1000025];
int dfs3(ll u,ll fa){
	mad=max(mad,dep[u]);
	for(auto v:g[u]){
		if(v==fa)continue;
		ffa[v]=u;
		dep[v]=dep[u]+1;
		dfs3(v,u);
	}
	return 0;
}
ll n,k;
ll r=0;
ll calc(ll i,ll j){
	
				A=i;
				B=j;
				ll K=k-2;
				R(k,1,n)dep2[k]=1e15;
				dfs2(i,0,0);
				dfs2(j,0,0);
				priority_queue<node> pq;
				for(auto v:g[i]){
					if(dfn[v]<dfn[i])continue;
					if(v==i||v==j)continue;
					pq.push({v,md[v]-dep[v]});
				}
				for(auto v:g[j]){
					if(dfn[v]<dfn[j])continue;
					if(v==i||v==j)continue;
					pq.push({v,md[v]-dep[v]});
				}
				while(!pq.empty()&&K){
					ll tt=pq.top().id;
					pq.pop();
					for(auto v:g[tt]){
						if(dfn[v]<dfn[tt])continue;
						if(v==i||v==j)continue;
						pq.push({v,md[v]-dep[v]});
					}
					K--;
				}
				ll ma=0;
				R(k,1,n)if(dep2[k]!=1e15)ma=max(ma,dep2[k]);
				if(!pq.empty())ma=max(ma,pq.top().v);
				return ma;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		R(i,1,n)g[i].clear();
		R(i,1,n-1){
			ll u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		dep[1]=0;
		mad=0;
		dfs3(1,0);
		R(i,1,n)if(dep[i]==mad){
			dep[i]=0;
			dfs3(i,0);
			break;
		}
		R(i,1,n)if(dep[i]==mad){
			r=i;
			break;
		}
		R(i,1,mad/2)r=ffa[r];
//		cout<<id<<'\n';
		ll mi=n;
		cnt=0;
		dep[r]=0;
		dfs(r,0);
		R(i,1,n){
			R(j,i+1,n){
				if(i==r||j==r)continue;
				mi=min(mi,calc(i,j));
//				if(ma==1)cout<<r<<" "<<i<<" "<<j<<'\n';
			}
		}
//		cnt=0;
//		dep[ffa[r]]=0;
//		dep[r]=0;
//		dfs(ffa[r],r);
//		dfs(r,ffa[r]);
//		mi=min(mi,calc(ffa[r],r));
		cout<<mi<<"\n";
	}
	return 0;
}
