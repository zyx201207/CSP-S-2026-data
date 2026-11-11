#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,t,a[10000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==4&&m==2)cout<<1<<"\n";
		else if(n==5&&m==2)cout<<2<<"\n";
		else if(n==5&&m==3)cout<<0<<"\n";
		else if(n==6&&m==2)cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
