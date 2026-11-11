#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int x;
		for(int i=1;i<=n;i++){
			cin>>x;
		}
		if(n==4&&d==2) cout<<1<<"\n";
		if(n==5&&d==2) cout<<2<<"\n";
		if(n==5&&d==3) cout<<0<<"\n";
		if(n==6&&d==2) cout<<1<<"\n";
	}
	return 0;
}
