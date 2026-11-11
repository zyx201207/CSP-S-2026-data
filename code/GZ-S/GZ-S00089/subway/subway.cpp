// GZ-S00089 黄浩然 贵阳市第三中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define pll pair<ll,ll>
struct ed{
	ll u ,w;
};
void fx(){
	ll c ,n ,m ,d ,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll>w(m+1,0);
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}

	vector<vector<ll> >a(n+1,vector<ll>(m+1,0));
	vector<vector<ll> >t(n+1,vector<ll>(m+1,0));
	vector<vector<ll> >micost(n+1,vector<ll>(n+1,1e18));
	map<ll,vector<ll> >mp;
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			ll now=a[i][j];
			mp[now].push_back(i);
			for(ll p=0;p<mp[now].size();p++){
				micost[i][mp[now][p]]=micost[mp[now][p]][i]=min(micost[mp[now][p]][i],t[i][now]+t[mp[now][p]][now]);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				micost[i][j]=min(micost[i][j],micost[i][k]+micost[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;cin>>x>>y;
		ll ans=w[x]+w[y];
		ll cost=1e18;
		for(ll i=0;i<mp[x].size();i++){
			for(ll j=0;j<mp[y].size();y++){
				cost=min(cost,t[mp[x][i]][x]+t[mp[y][j]][y]+micost[mp[x][i]][mp[y][j]]);
			}
		}
		cout<<ans+cost<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll t=1;
	while(t--)fx();
}


