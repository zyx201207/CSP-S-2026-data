#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 5e5+5;
int c,n,m,d,q;
int k[505];
ll ww[N];
vector<pair<int,ll> >v[N];
ll f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	fr(i,1,m)cin>>ww[i];
	fr(i,1,n)fr(j,1,n)f[i][j] = 1e17;
	fr(i,1,n)f[i][i] = 0;
	fr(i,1,n){
		cin>>k[i];
		fr(j,1,k[i]){
			int s1;ll s2;
			cin>>s1>>s2;
			v[s1].pb({i,s2});
		}
	}
	fr(u,1,m){
		for(int i=0;i<(int)v[u].size();i++){
			for(int j=0;j<(int)v[u].size();j++){
				int x = v[u][i].fi,y = v[u][j].fi;ll z = v[u][i].se+v[u][j].se;
				if(x==y)continue;
				f[x][y] = min(f[x][y],z);
			}
		}
	}
	fr(i,1,n){
		fr(j,1,n){
			fr(l,1,n){
				f[j][l] = min(f[j][i]+f[i][l],f[j][l]);
			}
		}
	}
	while(q--){
		int x,y;ll ans = 1e18;
		cin>>x>>y;
		for(int i=0;i<(int)v[x].size();i++){
			for(int j=0;j<(int)v[y].size();j++){
				int xx = v[x][i].fi,yy = v[y][j].fi;ll z = v[x][i].se+v[y][j].se;
				ans = min(ans,f[xx][yy]+z);
			}
		}
		ans = ans+ww[x]+ww[y];
		cout<<ans<<"\n";
	}
	
	return 0;
}
