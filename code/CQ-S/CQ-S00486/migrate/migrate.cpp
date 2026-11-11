#include<bits/stdc++.h>
using namespace std;
long long c,t,fn,n,d,x[5005],cnt[5005][5005],dp[5005][5005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int time=1;time<=t;time++){
		ans=0;
		cin>>fn>>d;
		n=fn;
		bool f=1;
		for(int i=1;i<=fn;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d&&f&&i!=1){
				n=i-1;
				f=0;
			}
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				if(x[r]-x[l]<=d){
					dp[l][r]=1;
					continue;
				}
				if(len!=2) dp[l][r]=0x3f3f3f3f;
				for(int k=l+1;k<r;k++){
					if(dp[l][r]==dp[l][k]+dp[k][r]) cnt[l][r]++;
					if(dp[l][r]>dp[l][k]+dp[k][r]) cnt[l][r]=1;
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]);	
				}
			} 
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				if(cnt[l][r]==2) ans++;
			} 
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
