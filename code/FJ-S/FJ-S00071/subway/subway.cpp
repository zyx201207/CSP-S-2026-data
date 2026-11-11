#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i8;
const ll N=500+7,M=1e6+5,inf=(1ll<<60),mod=1e9+7;
using namespace std;
vector <ll> ddd[M];
vector <ll> wi[M];
ll dis[N][N];
ll w[M];
ll c,n,m,d,q; 
inline ll minn(ll x,ll y){return (x<y?x:y);}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int  i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		while(k--){
			ll x,y;
			cin>>x>>y;
			ddd[x].push_back(i),wi[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		ll len=ddd[i].size();
		for(int x=0;x<len;x++){
			for(int y=0;y<x;y++){
				dis[ddd[i][x]][ddd[i][y]]=minn(dis[ddd[i][x]][ddd[i][y]],wi[i][x]+wi[i][y]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=minn(dis[i][j],dis[j][i]);
		}
	}
	for(int k=1;k<=n;k++){ 
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=minn(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<dis[i][j]<<endl;
//		}
//	}
	while(q--){
		ll x,y,ans=inf;
		cin>>x>>y;
		for(int i=0;i<ddd[x].size();i++){
			for(int j=0;j<ddd[y].size();j++){
				ans=minn(ans,dis[ddd[x][i]][ddd[y][j]]+wi[x][i]+wi[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}

