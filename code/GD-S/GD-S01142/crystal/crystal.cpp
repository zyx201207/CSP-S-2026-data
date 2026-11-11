#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5;
long long n,m;
long long v[N],a[N],dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		
		 
	}
	sort(v+1,v+1+n);
	dp[1]=0;
	for(int i=n;i>=2;i--){
		for(int j=i-1;j>=1;j--){
			dp[i]=dp[i]+v[i]-v[j];
			if(dp[i]==m){
				cout<<i;
				return 0;
			}
		}
	}
	/*for(int i=n;i>=1;i--){
		if(dp[i]==m){
			cout<<i;
			return 0;
		}else if(m<dp[i]&&m>dp[i+1]&&i!=n){
			cout<<i<<endl;
			return 0;
		}
	}*/

	return 0;
} 
