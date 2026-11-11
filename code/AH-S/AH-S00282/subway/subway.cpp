#include <bits/stdc++.h>
using namespace std;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll c,n,m,d,q,w[500005],k[505],x,y,z,t[505][500005];
vector<vector<pair<ll,ll> > > G(505);
vector<ll> ia[500005];
ll PP[505][505];
int main(void){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	F;
	ll i,j,K;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;++i)cin>>w[i];
	for(i=1;i<=n;++i){
		cin>>k[i];
		for(j=1;j<=k[i];++j){
			cin>>x>>y;
			t[i][x]=y;
			ia[x].push_back(i);
		}
	}
	memset(PP,0x7f,sizeof(PP));
	for(i=1;i<=m;++i){
		ll iasz=ia[i].size();
		for(j=0;j<iasz;++j){
			for(K=j+1;K<iasz;++K){
				x=ia[i][j],y=ia[i][K],z=t[x][i]+t[y][i];
				G[x].push_back({y,z}),PP[x][y]=PP[y][x]=z;
			}
		}
	}
	for(i=1;i<=n;++i)PP[i][i]=0;
	for(K=1;K<=n;++K){
		for(i=1;i<=n;++i){
			if(PP[i][K]==0x7f7f7f7f7f7f7f7f)continue;
			for(j=1;j<=n;++j){
				if(PP[j][K]==0x7f7f7f7f7f7f7f7f)continue;
				if(PP[i][j]>PP[i][K]+PP[K][j])PP[i][j]=PP[i][K]+PP[K][j];
			}
		}
	}
	while(q--){
		cin>>x>>y,K=LLONG_MAX;
		ll ix=ia[x].size(),iy=ia[y].size();
		for(i=0;i<ix;++i){
			for(j=0;j<iy;++j){
				K=min(K,PP[ia[x][i]][ia[y][j]]+t[ia[x][i]][x]+t[ia[y][j]][y]);
			}
		}
		cout<<w[x]+w[y]+K<<"\n";
	}
	return 0;
}
