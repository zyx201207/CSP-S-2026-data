#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,m,a[N],dp[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];			
	}
	dp[1]=a[1];
	dp[0]=2147483647;
	for(int i=2;i<=n;i++){
		int k=min(m,i);
		for(int j=k;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
} 
