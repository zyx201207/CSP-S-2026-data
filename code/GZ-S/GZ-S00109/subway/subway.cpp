//@贵阳市第三中学 李盱盈 GZ-S00109
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll c,n,m,d,q;
void zs(){
	cin>>c>>n>>m>>d>>q;
	vector<ll>w(m+1,0);
	for(ll i=1;i<=m;i++)cin>>w[i];//出站，进站 
	vector<vector<pll> >a(m+1);//一个站台属于的地铁线路
	vector<vector<pll> >ed(n+1);
	vector<vector<ll> >dist(n+1,vector<ll>(n+1,1e18));//厅，台  
	for(ll i=1;i<=n;i++){
		dist[i][i]=0;
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,t;
			cin>>x>>t;
			a[x].push_back({i,t});
		}
	}
	for(ll i=1;i<=m;i++){
		ll k=a[i].size();
		for(ll x=0;x<k;x++){
			for(ll y=0;y<k;y++){
				if(x==y)continue;
				ll w1=a[i][x].second,w2=a[i][y].second;
				ll id1=a[i][x].first,id2=a[i][y].first;
				dist[id1][id2]=dist[id2][id1]=w1+w2;
				ed[id1].push_back({id2,w1+w2});
				ed[id2].push_back({id1,w1+w2});
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j)continue;
			for(ll k=1;k<=n;k++){
				if(dist[i][k]>=1e18||dist[i][k]>=1e18)continue;
				if(dist[i][k]+dist[k][j]<dist[i][j])dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	while(q--){
		ll s,t,ans=1e18;
		cin>>s>>t;
		ll s1=a[s].size(),s2=a[t].size();
		for(ll i=0;i<s1;i++){
			for(ll j=0;j<s2;j++){
				ll x1=a[s][i].first,x2=a[t][j].first;
				ll w1=a[s][i].second,w2=a[t][j].second;
				ans=min(ans,dist[x1][x2]+w[s]+w[t]+w1+w2);
			}
		}
		cout<<ans<<"\n";
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll t=1;
	//cin>>t;
	while(t--)zs();
	return 0;
}
//8+2+4+7
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

