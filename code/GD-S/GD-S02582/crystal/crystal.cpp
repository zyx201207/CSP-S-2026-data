#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005],cf[500004];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
    	cf[i]=a[i+1]-a[i];
	}
	int dp[500005],longest=-1,lng=0;
	dp[0]=0;
	for(int i=1;i<n;i++){
		if(dp[i-1]+cf[i]<=m){
			lng++;
			dp[i]=dp[i-1]+cf[i];
		}
		else{
			dp[i]=dp[i-1]+cf[i];
			int j=i-1;
			while(dp[i]<=m){  
				dp[i]-=cf[j];j--;lng--;
			}
		}
		if(lng>longest){
			longest=lng;
		}
	}
	cout<<longest;
	return 0;
}
