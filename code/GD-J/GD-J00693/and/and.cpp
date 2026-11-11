#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a.begin()+1,a.end());
	vector<vector<int>> dp(n+1vector);
	for(int i=1;i<=n;i++) dp[i]=a[i];
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i],a[i]&dp[i-1]);
	} 
	cout<<dp[n];
	return 0;
} 
