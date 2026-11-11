#include <bits/stdc++.h>
using namespace std;
long long x[2000050];
long long dp[5050][5050],dis[5050][5050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;
		long long d;
		cin>>n>>d;
		long long ans=0;
		for(int xs=1;xs<=n;xs++)
			dp[xs][xs]=1;
		for(int xs=1;xs<=n;xs++){
			scanf("%lld",&x[xs]);
			for(int xs2=1;xs2<xs;xs2++){
				dis[xs][xs2]=1e18;
				dp[xs][xs2]=0;
				for(int xs3=xs-1;xs3>=xs2;xs3--){
					if(x[xs]-x[xs3]>d){
						break;
					}
					dis[xs][xs2]=min(dis[xs][xs2],dis[xs3][xs2]+1);
					if(dis[xs3][xs2]<dis[xs3+1][xs2])dp[xs][xs2]=0;
					dp[xs][xs2]+=dp[xs3][xs2];
				}
				if(dp[xs][xs2]==2){
					ans++;
				}
				//cout<<dp[xs][xs2]<<" ";
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
