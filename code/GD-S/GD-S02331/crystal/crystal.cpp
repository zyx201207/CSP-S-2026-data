#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],dp[500500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	cout<<m/2;
	return 0;
}
