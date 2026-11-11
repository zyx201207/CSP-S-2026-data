#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505;
const ll M=5e5+5;
const ll MAX=1e18;
ll op,n,m,D,q;
ll W[M];
ll kk[N];
vector<ll>a[N],ti[N];
struct note{
	ll v,w;
};
vector<note>d[M];
ll s[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>op>>n>>m>>D>>q;
	for(ll i=1;i<=m;i++){
		cin>>W[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>kk[i];
		a[i].push_back(0);
		ti[i].push_back(0);
		for(ll j=1;j<=kk[i];j++){
			ll x,y;
			cin>>x>>y;
			note t;
			t.v=i,t.w=y;
			d[x].push_back(t);
			a[i].push_back(x);
			ti[i].push_back(y);
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			s[i][j]=s[j][i]=MAX;
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<d[i].size();j++){
			for(ll k=j+1;k<d[i].size();k++){
				ll u=d[i][j].v,v=d[i][k].v,w=d[i][j].w+d[i][k].w;
				s[u][v]=s[v][u]=min(s[u][v],w);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=MAX;
		for(ll i=0;i<d[x].size();i++){
			for(ll j=0;j<d[y].size();j++){
				ll u=d[x][i].v,v=d[y][j].v,w=d[x][i].w+d[y][j].w;
				ans=min(ans,W[x]+W[y]+w+s[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
