#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll inf=1e16;
void chmin(ll &x,const ll &y){
	if(y<x){
		x=y;
	}
}
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<int> k(n+1);
	vector<ll> w(m+1);
	vector<vector<int>> a(n+1);
	vector<vector<ll>> t(n+1),dis(n+1,vector<ll>(n+1,inf));
	vector<vector<pii>> choice(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			choice[a[i][j]].emplace_back(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int p1=0;p1<k[i];p1++){
			for(const pii &c:choice[a[i][p1]]){
				int j=c.first,p2=c.second;
				chmin(dis[i][j],t[i][p1]+t[j][p2]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				chmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dis[i][j]==inf){
//				dis[i][j]=-1;
//			}
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	return 0;
	
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res=inf;
		for(const pii &pi:choice[x]){
			for(const pii &pj:choice[y]){
				int i=pi.first,p1=pi.second;
				int j=pj.first,p2=pj.second;
				chmin(res,dis[i][j]+t[i][p1]+t[j][p2]);
			}
		}
		cout<<w[x]+w[y]+res<<"\n";
	}
	return 0;
}
