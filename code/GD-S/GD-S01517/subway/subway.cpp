#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,aa,tt,w[500005],k[505],dis[505][505],xr,yr,ans;
vector<int> a[505],t[505];
vector<pair<int,int> > vec[500005];
pair<int,int> hsq,hhx;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			vec[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=LLONG_MAX;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			hsq=vec[i][j];
			for(int qq=j+1;qq<vec[i].size();qq++){
				hhx=vec[i][qq];
				dis[hsq.first][hhx.first]=min(dis[hsq.first][hhx.first],hsq.second+hhx.second);
				dis[hhx.first][hsq.first]=dis[hsq.first][hhx.first];
			}
		}
	}
	for(int v=1;v<=n;v++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][v]!=LLONG_MAX&&dis[v][j]!=LLONG_MAX) dis[i][j]=min(dis[i][j],dis[i][v]+dis[v][j]);
			}
		}
	}
	while(q--){
		cin>>xr>>yr;
		ans=LLONG_MAX;
		for(int i=0;i<vec[xr].size();i++){
			hsq=vec[xr][i];
			for(int j=0;j<vec[yr].size();j++){
				hhx=vec[yr][j];
				ans=min(ans,hsq.second+hhx.second+dis[hsq.first][hhx.first]);
			}
		}
		cout<<ans+w[xr]+w[yr]<<'\n';
	}
	return 0;
}
