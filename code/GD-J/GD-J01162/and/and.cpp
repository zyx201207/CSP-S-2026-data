#include<bits/stdc++.h>

using namespace std;

int dp[2010][2010];


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m,s;
	int ans=0;
	cin>>n>>m;
	int a[200010];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i!=j){
				dp[i][j]=(a[i]&a[j]);
			}

		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;

	return 0;
}
