#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],dp[200010];
bool cmp(int a,int b) {
	return a>b;
} 
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ;i <= n;i++) {
		scanf("%d",&a[i]); 
	} 
	sort(a+1,a+n+1,cmp);
	for(int i = 1 ;i <= n ;i++) {
		for(int j = m ;j >= 1 ;j--) {
			if(dp[j] > a[i]) break;
			if(j == 1) dp[j] = max(dp[j],a[i]);
			else dp[j] = max(dp[j],dp[j-1]&a[i]);
		} 
	}
	cout<<dp[m];	
	return 0;
} 
