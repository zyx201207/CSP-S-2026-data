#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200005],ans;
vector<long long> dp[2][200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	long long i,j,k;
	while(t>0){
		t--;
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<n;i++){
			dp[0][i].push_back(n-1);
			dp[1][i].push_back(n-1);
			for(j=i+1;j<=n;j++){
				dp[0][i].push_back(a[n]-a[1]+2);
				dp[1][i].push_back(0);
			}			
		}
		for(i=1;i<=n-1;i++){
			for(j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					//cout<<"t "<<j<<" "<<i<<" ";
					dp[0][i][j-i]=1;
					dp[1][i][j-i]=1;
					for(k=1;k<i;k++){
						if(dp[0][k][j-k]==dp[0][k][i-k]+1){
							if(dp[1][k][j-k]==2) ans--;
							dp[1][k][j-k]+=dp[1][k][i-k];
							if(dp[1][k][j-k]==2) ans++;
						}
						if(dp[0][k][j-k]>dp[0][k][i-k]+1){
							dp[0][k][j-k]=dp[0][k][i-k]+1;
							if(dp[1][k][j-k]==2) ans--;
							dp[1][k][j-k]=dp[1][k][i-k];
							if(dp[1][k][j-k]==2) ans++;
						}
					}
				}
				else j=n+1;
			}
		}
		/*for(i=1;i<n;i++){
			cout<<i<<"\n";
			for(j=i+1;j<=n;j++){
				cout<<j<<" "<<dp[0][i][j-i]<<" "<<dp[1][i][j-i]<<"\n";
			}
			cout<<"\n";
		}*/
		printf("%lld\n",ans);
		for(i=1;i<n;i++){
			a[i]=0;
			for(j=i;j<=n;j++){
				dp[0][i].pop_back();
				dp[1][i].pop_back();
			}
		}
		a[n]=0;
	}
	return 0;
}
