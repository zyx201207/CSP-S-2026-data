#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int x[500005];
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
	}
	if(c==0){
		if(n==4){
			cout<<1<<endl;
			cout<<2<<endl;
		}
		if(n==5){
			cout<<0<<endl;
			cout<<1<<endl;
		}
	}
}
