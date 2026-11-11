#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
namespace s1{
int dist[1010][1010];
int a[1010][1010],t[1010][1010];
int w[1010];
void solve(){
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];++j)
			cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=a[i][0];++j) for(int k=1;k<=a[i][0];++k)
			dist[a[i][j]][a[i][k]]=min(dist[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
	}
//	for(int i=1;i<=m;++i){
//		for(int j=1;j<=m;++j){
//			if(dist[i][j]==0x3f3f3f3f) cout<<-1<<' ';
//			else cout<<dist[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=m;++k){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dist[x][y]<<endl;
	}
}
};

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c<=11)
		s1::solve();
	return 0;
}
/*
1-11:±©Á¦½¨Í¼floyed,O(m^3+q) sum(k)<=1000
*/
//[32,44]
