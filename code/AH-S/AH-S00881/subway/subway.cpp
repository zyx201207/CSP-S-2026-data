#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int inf=INT_MAX;
int cnt,c,n,m,d,q,w[500005],a[21],t[21];
ll dis[1005][1005];
void Floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;++i){
			for (int j=1;j<=m;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;++j)
	dis[i][j]=inf;
	for(int k,i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;++j){
			for(int s=j+1;s<=k;++s){
				dis[a[j]][a[s]]=t[j]+t[s];
				dis[a[s]][a[j]]=t[j]+t[s];
			}
		}
	}
	Floyd();
	int u,v;
	while(q--){
		cin>>u>>v;
		cout<<(long long)dis[u][v]+w[u]+w[v]<<'\n';
	}
	return 0;
}
