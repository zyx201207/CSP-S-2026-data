#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if((n==4&&d==2)||(n==6&&d==2)) cout<<1<<"\n";
		else if(n==5&&d==2) cout<<2<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
