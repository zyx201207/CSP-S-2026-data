#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000005];
long long dp[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int k=1;k<=n;k++){
			for(int j=m;j>=0;j--){
				if(i!=k){
					dp[j]=max((dp[j]&a[i]),max((a[i]&a[k]),(dp[j]&a[k])));
					
				}
				continue;
			}
		}
		
	}
	cout<<dp[m];
	

	
	return 0;
}
