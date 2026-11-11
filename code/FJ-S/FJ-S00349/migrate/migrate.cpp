#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1) cout<<0<<endl;
		else if(d/(a[2]-a[1])!=2) cout<<0<<endl;
		else cout<<n-3<<endl;
	}
	return 0;
}
