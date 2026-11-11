#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[2000006],dp[2000006],s[2000006],sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=2000000;i++)s[i]=10000;
		for(int i=1;i<=2000000;i++)dp[i]=0;
		s[1]=0;
		sum=0;
		dp[1]=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d&&s[i]+1<=s[j]){
					if(s[i]+1==s[j]){
						dp[j]+=dp[i];
					}else{
						dp[j]=dp[i];
						s[j]=s[i]+1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			//cout<<dp[i]<<" "<<s[i]<<endl;
			if(dp[i]==2)sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
