#include<bits/stdc++.h> 
using namespace std;
long long n,a[200005],dp[200005],m,maxn=-INT_MAX;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=m;j>=1;j--){
			if(j==m){
				dp[j]=a[i];
			}else{
				dp[j]=max(dp[j],dp[j-1]+(dp[j-1]&a[i]));
			}
			
			
		}
	}

	cout<<dp[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
