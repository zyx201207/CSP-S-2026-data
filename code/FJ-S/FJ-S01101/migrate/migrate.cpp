#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=9){
			cout<<0<<endl;
		}
		else{
			if(x[3]-x[1]<=d){
				cout<<1;
			}
			else{
				cout<<0;
			}
			cout<<endl;
		}
		
	}
	
	return 0;
}
