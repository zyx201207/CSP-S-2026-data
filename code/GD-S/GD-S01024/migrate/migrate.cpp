#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,d,x[5005],dis[5005][5005],cnt[5005][5005];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=2e18,cnt[i][j]=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(x[i]-x[j])<=d) dis[i][j]=dis[j][i]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[j][k]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(k==i||k==j) continue;
				if(dis[i][k]+dis[k][j]==dis[i][j]){
					cnt[i][j]++;
//					cout<<i<<' '<<j<<' '<<k<<' '<<dis[i][j]<<'\n';
				}
			}
		}
	}
	int ans=0;
//	cout<<dis[1][4]<<' ';
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++)if(cnt[i][j]==2) ans++;
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>c>>t;
	while(t--) solve();
	return 0;
} 
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558
-111111111111111116 111111111111111105
333333333333333326 555555555555555547
999999999999999989
*/

