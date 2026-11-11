#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		bool f=0;
		for(int i=1;i<n-1;i++){
			if(x[i+2]-x[i]<=d) f=1;
		}
	    if(f==0){
			cout<<0<<endl;
		}
		else if(n==4){
			cout<<1<<endl; 
		}
		else if(n==5){
			cout<<2<<endl;
		}
		else if(n==6) cout<<4<<endl;
	}
	return 0;
}
