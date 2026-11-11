#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int a[2000005],s[2000005];
int dp[3005][3005],st[3005][3005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		s[0]=0;
		int ans=0;
		bool dc=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
			//s[i]=s[i-1]+a[i];
		}
		//continue ;
		if(n>10000){
			cout<<0<<"\n";
			continue ;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=-1;
			}
		}
		for(int i=1;i<n;i++){
			int k=a[i];
			for(int j=i+1;j<=n;j++){
				if(a[j]-k>d){
					if(a[j]-a[j-1]<=d){
						dp[i][j]=dp[i][j-1]+1;
						k=a[j-1];
					}else{
						break;
					}	
				}else{
					dp[i][j]=max(1ll,dp[i][j-1]);
				}
			}
		}
	//	for(int i=1;i<n;i++){
		//	for(int j=i+1;j<=n;j++){
			//	cout<<dp[i][j]<<" "; 
			//}
			//cout<<"\n";
		//}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int u=0;
				if(j-i+1>=4){
					int k=j-1;
					while(k>=i+1&&a[j]-a[k]<=d){
						if(dp[i][k]+1==dp[i][j]){
							u+=st[i][k];
							if(u>2){
								break;
							}
						}
						k--;
					}
					st[i][j]=max(u,1ll);
				}else{
					st[i][j]=1;
				}
				if(u==2){
					ans++;
					//cout<<i<<" "<<j<<"\n";
				}
				
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
