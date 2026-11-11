#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[100005],dp[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>v[i];
	}
	for(int i=1;i<=m;i++)dp[i]=v[1];dp[0]=INT_MAX-1;
	for(int i=2;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],(dp[j-1]&v[i]));
		}
	}cout<<dp[m];
	return 0;
}
