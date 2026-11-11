#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,d,m,n,q,w[510]; 
bool vis[510];
ll mm[510][510]; 

struct node{
	ll u;
	ll ti;
};
vector<node> mp[510];

struct que{
	ll u;
	ll ti;
	bool operator &(const que pp){
		return pp.ti > ti;
	}
};
priority_queue<que> p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			mm[x][i]=y;
		}
	}
	return 0;
}
