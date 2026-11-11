#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5e5+10;
#define ll long long
struct node{
	//a表示道路编号,t表示距离 
	ll a,t;
};
ll c,n,m,d,q;
ll w[N];
//a[i]表示连接i的所有道路 
vector<node> a[N];
ll dis[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<a[i].size();j++){
			node u=a[i][j];
			for(ll k=0;k<a[i].size();k++){
				node v=a[i][k];
				dis[u.a][v.a]=min(dis[u.a][v.a],u.t+v.t);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll x,y,ans=1e18;
		cin>>x>>y;
		for(ll i=0;i<a[x].size();i++){
			node u=a[x][i];
			for(ll j=0;j<a[y].size();j++){
				node v=a[y][j];
				ans=min(ans,u.t+dis[u.a][v.a]+v.t);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
