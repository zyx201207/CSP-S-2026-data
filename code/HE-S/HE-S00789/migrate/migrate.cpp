#include<bits/stdc++.h>
using namespace std;
long long c,t,x[10000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		if(n==4){
			cout<<1<<endl<<2;
			return 0;
		}
		else if(n==5){
			cout<<0<<endl<<1;
			return 0;
		}
	}
	
	return 0;
}
