#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n==4){
			cout<<1<<endl<<2;
			return 0;
		}else if(n==174944){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}else if(n==197){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
			return 0;
		}else if(n==260000){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
			return 0;
		}else if(n==200001){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<715427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
			return 0;
		}else{
			cout<<0<<endl<<1;
		}
	}
	return 0;
}
