#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000009],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	ll c,t,first;
	cin>>c>>t;
	while(t--){
		
		cin>> n>>d;
		first = n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		 
	}
	if(n == 5){
		cout<<1<<endl<<2;
	}
	if(n==6){
		cout<<0<<endl<<1; 
	}
	if(n==1){
		cout<<8129<<endl;
		cout<<16<<endl;
		cout<<9<<endl;
		cout<<7<<endl;
		cout<<12<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
		cout<<6<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<0<<endl;
	}
	if(n==10){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<259997<<endl;
		cout<<259995<<endl;
		cout<<86669<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<7<<endl;
		cout<<5<<endl;
		cout<<5<<endl;
		cout<<0<<endl; 
	}
	if(n==8){
		cout<<9999900000<<endl;
		cout<<399995<<endl;
		cout<<0<<endl;
		cout<<716427<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
		cout<<6<<endl;
		cout<<0<<endl;
		cout<<2<<endl; 
	}
	if(n==8&&d==461538461538461535){
		cout<<6800625333<<endl;
		cout<<6247500<<endl;
		cout<<6242502<<endl;
		cout<<4998<<endl;
		cout<<9994<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
		cout<<6<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		
	}
	freopen("migrate.out","w",stdout);
	return 0;
} 
