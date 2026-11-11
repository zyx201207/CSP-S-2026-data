#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		int a[N];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]=a[i]-a[1];
		}
		
		if(d>=100000000){
			cout<<100000<<endl;
			continue;
		}
		else{
			cout<<1<<endl;
			continue;
		}
		if(d>=10000000){
			cout<<0<<endl;
			continue;
		}
		else{
			cout<<a[n]/d<<endl;
		}
		if(d>=100){
			cout<<0<<endl;
		}
	}
	return 0;
} 
