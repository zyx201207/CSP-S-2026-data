#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const long long inf=LLONG_MAX/2;
const int MAXM=5e5+5,MAXN=505;
int c,n,m,D,p,w[MAXM];
vector<pair<int,ll> >a[MAXM];
vector<pair<int,ll> >g[MAXN];
long long d[MAXN][MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int v,t;
			cin>>v>>t;
			for(auto k:a[v]){
				int st=k.second+t;
				g[i].push_back({k.first,st});
				g[k.first].push_back({i,st});
			}
			a[v].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=inf;
		}
		d[i][i]=0;
		for(auto j:g[i]){
			int v=j.first;
			long long t=j.second;
			d[i][v]=min(d[i][v],t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for(auto i:a[x]){
			for(auto j:a[y]){
				ans=min(ans,d[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<(ans+w[x]+w[y])<<"\n";
	}
	return 0;
}
