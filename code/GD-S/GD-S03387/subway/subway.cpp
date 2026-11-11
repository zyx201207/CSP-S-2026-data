#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505;
const ll M=5e5+10;
ll c,n,m,d,q,dis[N][N],w[M];
vector<pair<ll,ll>> zhan[N];
vector<pair<ll,ll>> st[M];
ll minn[M],l,r;
void solve(){
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++){
		ll k; cin >> k;
		dis[i][i]=0;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin >> a >> t;
			zhan[i].push_back({a,t});
			st[a].push_back({i,t});
		}
		minn[i]=1e18;
	} 
	for(int i=1;i<=n;i++){
		for(auto x:zhan[i]){
			for(auto y:st[x.first]){
				if(i==y.first) continue ;
				minn[y.first]=min(minn[y.first],x.second+y.second);
			}
		}
		for(int j=1;j<=n;j++){
			if(i==j) continue ;
//			cout << i << " " << j << " " << minn[j] << "\n";
			dis[i][j]=minn[j];
			minn[j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	cout << q << "\n";
	while(q--){
		cin >> l >> r;
		ll ans=1e18;
		for(auto x:st[l]){
			for(auto y:st[r]){
				if(x.first==y.first) ans=w[l]+w[r]+x.second+y.second;
				else ans=min(ans,dis[x.first][y.first]+w[l]+w[r]+x.second+y.second);
			}
		}
		cout << ans << "\n";
	}
}
ll T=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	cin >> T;
	while(T--) solve();
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
