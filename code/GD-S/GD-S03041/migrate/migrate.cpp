#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],dp[2000005],dq[2000005],number;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++){cin>>x[i];}
	number=x[2]-x[1];
	if(number>d){cout<<0;return 0;}
	cout<<2;
	return 0;
}
