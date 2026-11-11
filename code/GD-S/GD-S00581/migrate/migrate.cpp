#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
int a[N],dp[N],ans[N];
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			dp[i]=1e9;
			ans[i]=0;
		}
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dp[1]=0;
		for(int i=1;i<n;i++){
			int j=i+1;
			while(a[i]+d<=a[j]){
				if(dp[i]+1==dp[j]){
					ans[j]++;
				}
				if(dp[i]+1<dp[j]){
					ans[j]=1;
					dp[j]=dp[i]+1;
				}
				j++;
			}
			cout<<dp[i]<<" ";
		}
		long long s=0;
		for(int i=1;i<=n;i++){
			if(ans[i]==2)s++;
		}
		cout<<s<<"\n";
	}
}
