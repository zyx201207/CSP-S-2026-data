#include <bits/stdc++.h>
using namespace std;
int a[200005],dp[200005],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=-1;
	}
	sort(a+1,a+n+1);
	cout<<a[n];
	return 0;
}
