#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<vector<ll>> a(n+1,vector<ll>(m+1,0));
	vector<vector<ll>> t(n+1,vector<ll>(m+1,0));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i][x]=1;
			t[i][x]=y;
		}
	}
	vector<vector<ll>> g(m+1,vector<ll>(m+1,INT_MAX));
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[i][j]!=1)continue;
			for(int z=1;z<=m;z++){
				if(a[i][z]!=1 && j==z)continue;
				g[j][z]=min(g[j][z],t[i][z]);
			}
		}
	}
	ll x,y; 
	vector<ll> d(m+1,INT_MAX);
	while(q--){
		cin>>x>>y;
		ll ans=w[x];
		d[x]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(x!=i){
					d[i]=min(d[i],d[x]+g[x][i]);
				}
			}
		}
	}
	return 0;
}
