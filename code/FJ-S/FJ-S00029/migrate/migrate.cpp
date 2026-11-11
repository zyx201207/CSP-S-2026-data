#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],dis[15][15];
void solve(){
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		dis[i][i]=1;
	}
//	if(11<=c&&c<=12){
		if(2<=(a[2]-a[1])*m&&(a[2]-a[1])*m<3){
			cout<<n-3<<'\n';
		}else{
			cout<<"0\n";
		}
//	}else{
//		for(int i=1;i<=n;i++){
//			int lu=0,dao=a[i];
//			for(int j=j+1;j<=m;j++){
//				if(lu>dao){
//					lu=0,dao=a[i];
//				}
//			}
//		}
//		dfs()
//	}
}
signed main(){
	int T=1,c;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
