#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAX=1073741823;
long long dp[200005],a[200005];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=MAX; 
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	
}

