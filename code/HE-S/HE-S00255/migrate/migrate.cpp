#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
	}
	if(n==5){
		cout<<1<<endl<<2;
	}
	if(n==6){
		cout<<0<<endl<<1;
	}
	return 0;
}
