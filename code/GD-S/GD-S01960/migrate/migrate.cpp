#include <bits/stdc++.h>
using namespace std;
long long n,T,i,j,k,x,c,d,y,m,a[500005],b[500005],cnt,ans,l,sum;
pair<long long,long long> dp[10005][10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dp[i][j].second=1e18;
				dp[i][j].first=1;
			}
			dp[i][i].first=1;
			dp[i][i].second=0;
		}
		for(i=1;i<n;i++){
			for(j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					for(k=1;k<j;k++){
						if(dp[j][k].second>dp[i][k].second+1){
							dp[j][k].second=dp[i][k].second+1;
							dp[j][k].first=dp[i][k].first;
						}
						else if(dp[j][k].second==dp[i][k].second+1){
							dp[j][k].first++;
						}
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<i;j++){
				if(dp[i][j].first==2){
					cnt++;
					//cout<<i<<' '<<j<<endl;
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
} 
