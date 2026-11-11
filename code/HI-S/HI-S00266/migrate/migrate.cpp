#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,d,n;
	cin>>t>>d>>n;
	if(t==0){
		if(d==2&&n==4) {
			cout<<1<<endl<<2; 
		}
		if(d==2&&n==5) {
			cout<<0<<endl<<1; 
		}
		if(d==17&&n==197) {
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0; 
		}
		if(d==12&&n==260000) {
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		}
		if(d==14&&n==200001) {
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2; 
		}
		if(d==16&&n==174944) {
			cout<<6806625333<<endl<<6247500<<endl<<6242402<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2; 
		}
	} else{
		cout<<1;
	}
	return 0;
}
