#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int nums[MAXN],dp[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	dp[1]=nums[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int num=1;num<=m;num++){
				dp[i]=max(dp[i],dp[j]&dp[i]);
			}
		}
	}
	//cout<<dp[n];
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	return 0;
}
