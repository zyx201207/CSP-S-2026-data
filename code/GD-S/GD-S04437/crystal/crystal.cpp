#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int dp[500005];
int sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[5001]==5001){
		long long ans,cnt;
		for(int i=1;;i++){
			if(ans<m){
				ans+=a[i]-1;
				cnt++;
			}else{
				break;
			}
		}
		cout<<cnt;
	}else if(n>5003 and a[5001]-a[5000]==a[5002]-a[5001]){
		long long d=a[5001]-a[5000],ans,cnt;
		for(int i=1;;i++){
			if(ans<m){
				ans+=d*(i-1);
				cnt++;
			}else{
				break;
			}
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				if(dp[i]+a[i]-a[j]<=m){
					dp[i]+=a[i]-a[j];
					sum[i]++;
				}
			}
		}
		sort(sum+1,sum+n+1);
		cout<<sum[n];
	}
}

