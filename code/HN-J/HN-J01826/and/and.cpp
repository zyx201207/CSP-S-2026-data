#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	long long a[200001];
	long long s[200001]; 
	long long dp[200001][200001];
	cin >>n>>m;
	cin >>a[0];
	s[0]=a[0];
	for(int i=1;i<n;i++){
		cin >>a[i];
		s[i]=s[i-1]&a[i];
	}
	dp[m-1][m-1]=s[m-1];
	for(int i=m;i<n;i++){
		for(int j=)
	    dp[i][m-1]=max(dp[i-1],dp[i-1]&a[i]);
	    
	}
	return 0;
}
