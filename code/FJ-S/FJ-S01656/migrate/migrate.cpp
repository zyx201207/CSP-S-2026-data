#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,mod=1e9+7,inf=2e18;
int c,T,n,d,a[N],dp[5005][5005],ans,vis[5005][5005];
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=inf;
			vis[i][j]=0;
		}
	}	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=d) dp[i][j]=dp[j][i]=1;
		}
	}
	for(int l=3;l<=n;l++){
		for(int i=1;i<=n;i++){
			int j=i+l-1;
			for(int k=i+1;k<=j-1;k++){
				if(dp[i][k]==inf||dp[k][j]==inf) continue;
				if(dp[i][j]!=inf&&dp[i][j]==dp[i][k]+dp[k][j]) vis[i][j]++;
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					vis[i][j]=0;
					dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vis[i][j]==1) ans++;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c<=6){
		while(T--){
			solve();
		}
		return 0;		
	}
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n<=3||d<(a[2]-a[1])*2) cout<<0<<'\n';
			else cout<<max(0ll,(n-d/(a[2]-a[1])*2+1))<<'\n';	
		}
		return 0;
	}
	if(c==13||c==14){
		int aa=0;
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				int l=1,r=i-1;
				while(l<=r){
					int mid=l+r>>1;
					if(a[i]-a[mid]>d) r=mid-1;
					else l=mid+1;
				}
				aa+=r+1;
			}
			cout<<aa<<'\n';
		}
	}	
	return 0;
}
