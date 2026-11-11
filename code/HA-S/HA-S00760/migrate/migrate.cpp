#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d,a[2000006];
int dis[5005][5005],sum[5005][5005];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum[i][j]=sum[j][i]=0;
			dis[i][j]=dis[j][i]=3e18;
			if(a[j]-a[i]<=d){
				sum[i][j]=sum[j][i]=1;
				dis[i][j]=dis[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k)continue;
				int x=dis[i][k]+dis[k][j];
				if(x<dis[i][j]){
					dis[i][j]=x;
					sum[i][j]=sum[i][k]*sum[k][j];
				}
				else if(x==dis[i][j]){
					sum[i][j]+=sum[i][k]*sum[k][j];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(sum[i][j]==2)ans++;
		}
	}
	cout<<ans<<"\n";	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
