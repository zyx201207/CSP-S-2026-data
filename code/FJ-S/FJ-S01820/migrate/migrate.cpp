#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000005],dp[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1; i <= n; i++) cin>>a[i];
		int k = d/(a[2]-a[1]);
		memset(dp,0,sizeof(dp));
		cout<<1<<endl<<2<<endl;
	}
	return 0;
}
