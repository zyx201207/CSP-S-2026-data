 #include<bits/stdc++.h>
using namespace std;
struct z{
	long long dao,duo;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int wq,t;
	cin>>wq>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		long long a[100010];
		for(int i=1;i<=n;i++)cin>>a[i];
		
		long long ans=0;
		for(int u=1;u<=n;u++){
			z dp[510];
			for(int j=u+1;j<=n;j++){
				dp[j].duo=1e9;
			}
	
			dp[u].dao=1;
			dp[u].duo=0;
			//a[u-1]=a[u];
			for(int i=u+1;i<=n;i++){
				for(int j=u;j<i;j++){
					if(a[i]-a[j]-m<=0){
						if(dp[i].duo>dp[j].duo+1){
							dp[i].duo=dp[j].duo+1;
							dp[i].dao=dp[j].dao;
						}
						else if(dp[i].duo==dp[j].duo+1)dp[i].dao+=dp[j].dao;
					}
				}
			}
			
			for(int i=1;i<=n;i++){
				if(dp[i].dao==2)ans++;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0; 
}
