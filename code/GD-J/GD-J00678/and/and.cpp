#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],dp[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i+=2){
		a[2]&=a[i];
	}
	cout<<n-m;
	return 0;
} 
