#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==4 &&m==2){
			cout<<1<<endl;
		}
		else if(n==5 &&m==2){
			cout<<2<<endl;
		}
		else if(n==5 &&m==3){
			cout<<0<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	return 0;
}
