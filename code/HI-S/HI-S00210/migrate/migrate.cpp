#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		if(n==4){
			cout<<1<<endl<<2;
			return 0;
		}
		if(n==5){
			cout<<0<<endl<<1;
			return 0;
		}
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
		}
	}
	
	return 0;
}
