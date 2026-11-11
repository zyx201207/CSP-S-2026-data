#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
ll c,n,m,k,u,v,ans,Inf=4e18,top,d,q;
ll w[500010],dis[510][510],mp[500010];
vector<pair<ll,ll>> G[500010];
pair<ll,ll> S;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	rep(i,1,m){
		cin >> w[i];
	}
	rep(i,1,n){
		rep(j,1,n) dis[i][j]=Inf;
		dis[i][i]=0;
	}
	rep(i,1,n){
		cin >> k;
		rep(j,1,k){
			top++;
			cin >> u >> v;
			G[u].push_back({i,v});
		}
	}
	rep(i,1,m){
		for(auto p1:G[i]){
			for(auto p2:G[i]){
				dis[p1.first][p2.first]=min(dis[p1.first][p2.first],p1.second+p2.second);
			}
		}
	}
	/*
	rep(i,1,n){
		for(auto p:g[i]){
			mp[p.first]=p.second;
		}
		rep(j,i+1,n){
			for(auto p:g[j]){
				if(mp[p.first]) dis[i][j]=min(dis[i][j],mp[p.first]+p.second),dis[j][i]=dis[i][j];
			}
		}
		for(auto p:g[i]){
			mp[p.first]=0;
		}
	}
	*/
	rep(k,1,n){
		rep(i,1,n) rep(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	while(q--){
		cin >> u >> v;
		ans=Inf;
		for(auto p1:G[u]){
			for(auto p2:G[v]){
				ans=min(ans,dis[p1.first][p2.first]+p1.second+p2.second);
			}
		}
		cout << ans+w[u]+w[v] << "\n";
	}
	return 0;
}
