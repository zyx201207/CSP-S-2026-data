#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
long long a[2000010],s[2000100],cnt1,sum,dp[5100][5100],o,o1;
int main(){
		freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	while(t--){
		o=1;
		o1=0;
		cnt1=0;
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];			
			if(i==2){
			o1=a[i]-a[i-1];	
			}
			else{
				if(i>2&&o1!=(a[i]-a[i-1])){
				o=0;	
				}
		}
			s[i]=a[i]-a[i-1];		
		}
		if(o==1){
			long long u=m/s[2];
			if(n>=2*u)cout<<(n-(2*u)+1)<<endl;	
			else cout<<0<<endl;
		}else{
			for(long long l=2;l<=n;l++){
				for(long long i=1;i+l-1<=n;i++){
					long long j=i+l-1,cnt=1e18,cnt2=0;
					if(a[j]-a[i]<=m)dp[i][j]=1;	
					else{
					for(int k=i+1;k<j;k++){
						if(dp[i][k]!=0&&dp[k][j]!=0){
							if(dp[i][k]+dp[k][j]<cnt){
								cnt=dp[i][k]+dp[k][j];
							dp[i][j]=dp[i][k]+dp[k][j];	
							cnt2=0;
							}
							if(dp[i][k]+dp[k][j]==cnt){
							cnt2++;	
							}
						}
					}
					if(cnt2==2)sum++;	
					}			
				}
			}
			cout<<sum<<endl;
		} 
	} 
	return 0;
}
