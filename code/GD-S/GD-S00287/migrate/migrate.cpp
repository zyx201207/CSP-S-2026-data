#include<bits/stdc++.h>
using namespace std;
long long c,n,d,t,a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<4){
			cout<<0<<"\n";
			continue;
		}
		for(int i=4;i<=n;i++){
			if(abs(a[i-1]-a[i-2])<=d&&abs(a[i-2]-a[i-1])<=d) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
