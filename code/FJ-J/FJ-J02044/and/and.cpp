#include<bits/stdc++.h>
using namespace std;
long long dp[200086],n,m,a[200086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	cout<<n-m+1;
	return 0;
}
