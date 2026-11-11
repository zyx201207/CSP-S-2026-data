#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		long long dis=d/(a[2]-a[1]);
		//cout<<dis<<endl;
		if(dis>=3||dis<=1)cout<<0<<endl;
		if(n<4)cout<<0<<endl;
		else cout<<n-3<<endl;
	}
	return 0;
}
