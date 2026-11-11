#include<bits/stdc++.h>
using namespace std;
long long dp[30][30];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,k;
	long long a[200010],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(k==n){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}else if(k==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			dp[i][k-1]=a[i];
			for(int j=1;j<i;j++){
				for(int t=0;t<k;t++){
					dp[i][t]=dp[j][t+1] & a[i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(dp[i][0],ans);
		}
	}
	cout<<ans;
	return 0;
}
