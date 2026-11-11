#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001];
vector<long long>dp[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		dp[1].push_back(a[i]);
	}
	for(int i=1;i<n;i++){
		dp[2].push_back(dp[1][i]-dp[1][i-1]);
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<n-i+1;j++){
			dp[i].push_back(dp[i-1][j]+(i-1)*dp[2][i+j-2]);
		}
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<n-i+1;j++){
			if(dp[i][j]<=m){
				cout<<i;
				return 0;
			} 
		}
	}
}
