#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005];
long long dp[500005],ans=1;//dp[i]表示对齐第i个的最优解(最多个数) 
long long rest[500005];//dp[i]的剩余能量 dp[i-1]可缩小检索范围 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	dp[1]=1,rest[1]=m; 
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			dp[i]=dp[i-1]+1;
			rest[i]=rest[i-1];
		}
		else{
			long long del=a[i]-a[i-1];//能量差 
			if(rest[i-1]>=dp[i-1]*del){
				dp[i]=dp[i-1]+1;
				rest[i]=rest[i-1]-dp[i-1]*del;
			}
			else{
				long long rec=rest[i-1];//recycle
				for(int j=i-dp[i-1];j<=i;j++){
					if(rec>=(i-j)*del){
						dp[i]=i-j+1;
						rest[i]=rec-(i-j)*del;
						break; 
					}
					rec+=a[i-1]-a[j];
				}
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans; 
	return 0;
}
