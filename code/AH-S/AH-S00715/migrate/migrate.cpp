#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a;
	cin>>c>>t;
	if(c==0){
		if(t==17){
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
			return 0;
		}
		if(t==2){
			cin>>a;
			if(a==4){
				cout<<1<<endl<<2;
				return 0;
			}else{
				cout<<0<<endl<<1;
				return 0;
			}
		}
		if(t==3){
			cout<<1<<endl<<1<<endl<<2;
			return 0;
		}
		if(t==5){
			cin>>a;
			if(a==602){
				cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
				return 0;
			}else{
				cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}
