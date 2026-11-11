#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,d;cin>>c>>d;
	for(int po=1;po<=d;po++){
		int n,m;cin>>n>>m;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<int> dp(n+1,0),dp2(n+1,0);
		int ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=n;j++) dp[j]=dp2[j]=0;
			for(int j=i+1;j<=i+m-1;j++){
				dp2[j]=1;
			}
			for(int j=i+1;j<=n;j++){
				for(int z=1;z<=m;z++){
					if(j-z>0 and abs(a[j]-a[j-z])<=m){
						dp[j]=dp[j]+dp[j-z]+dp2[j-z];
					}
				}
				if(dp[j]==2) ans++;
			}
		}		
		cout<<ans<<endl;
	}
	return 0;
} 
