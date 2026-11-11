#include<bits/stdc++.h>
using namespace std;
map<long long,char> mp; 
long long a[20034],ans,cnt,n,k,dp[20034][2000],maxx=-2e18;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	dp[i][1]=a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			for(int w=2;w<=k;w++){
				dp[i][w]=max(dp[i][w],a[i]&dp[j][w-1]);
			}
		}
	}
	for(int i=k;i<=n;i++){
		maxx=max(maxx,dp[i][k]);
	}
	cout<<maxx;
	return 0;
}
