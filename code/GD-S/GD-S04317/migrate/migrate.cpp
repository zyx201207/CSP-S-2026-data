#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if((x[2]-x[1])*2>d||(x[2]-x[1])*3<=d)cout<<0<<'\n';
		else cout<<n-3<<'\n';
	}
	return 0;
}
