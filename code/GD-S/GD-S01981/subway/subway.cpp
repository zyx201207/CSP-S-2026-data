#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
ll mp[505][505];
ll w[M],T;
vector<int> htr[M];
vector<ll> htrl[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<505;i++){
		for(int j=0;j<505;j++){
			mp[i][j]=2e9;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a;j<=k;j++){
			cin>>a>>T;
			htr[a].push_back(i);
			htrl[a].push_back(T);
		}
	}
	for(int i=1;i<=m;i++){
		int len=htr[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				mp[htr[i][j]][htr[i][k]]=mp[htr[i][k]][htr[i][j]]=htrl[i][j]+htrl[i][k];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k) continue;
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		mp[i][i]=0;
	}
	/*
	for(int i=1;i<=m;i++){
		for(int j=0;j<htr[i].size();j++){
			
		}
	}*/
	while(q--){
		ll ans=9e18;
		int x,xlen,y,ylen;
		cin>>x>>y;
		xlen=htr[x].size(),ylen=htr[y].size();
		for(int i=0;i<xlen;i++){
			for(int j=0;j<ylen;j++){
				int xr=htr[x][i],yr=htr[y][j];
				ans=min(mp[xr][yr]+htrl[x][i]+htrl[y][j],ans);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
