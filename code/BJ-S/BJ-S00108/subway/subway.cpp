#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=5e5+5;
ll n,m;
ll w[M];
ll line[N][M];
ll dist[M];
bool vis[M],trans[M];
ll dij(ll st,ll ed){
	ll res1=INT_MAX;
	ll res2=INT_MAX;
	for(ll i=1;i<=n;i++){
		if(line[i][st]!=0) res1=min(res1,line[i][st]);
		if(line[i][ed]!=0) res2=min(res2,line[i][ed]);
	}
	return res1+res2;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		while(k--){
			ll j,y;
			cin>>j>>y;
			line[i][j]=y;
		}
	}
	while(q--){
		ll st,ed,ans;
		cin>>st>>ed;
		ans=w[st]+w[ed];
		ans+=dij(st,ed);
		cout<<ans<<'\n';
	}
	return 0;
}
