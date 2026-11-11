#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
int n,m;
long long a[maxn],dp[maxn],min_a=INT_MAX;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[1]=a[i];
		for(int j=m;j>1;j--){
			dp[j]=(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
} 
