#include <iostream>


#include <bits/stdc++.h>

const int T=5e5+5;
long long n,m,ans;
long long  arr[T];
long long  dp[T];
using namespace std;
int main(){
		freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
		
		
	
	sort(arr,arr+n);
	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i]=arr[i]-arr[i-1];
	}
	
	
	for(long long  i=0;i<n;i++){
		long long  cnt=0;
		for(long long  j=i+1;j<n;j++){
			
			cnt+=dp[j]*(j-i);
			if(cnt>m)break;
			ans=max(j-i+1,ans);
		}
	}
	cout<<ans;
	return 0;
	
}
