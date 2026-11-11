#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000006],dp[2000006],js[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if((a[2]-a[1])*3>d&&(a[2]-a[1])*2<=d){
			cout<<n-2<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
