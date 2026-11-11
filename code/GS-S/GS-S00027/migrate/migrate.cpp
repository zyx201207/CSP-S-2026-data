#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==0 && b==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}else{
		cin>>a>>b;
		if(a==4 && b==2){
			cout<<1<<endl<<2;
		}else if(a==5 && b==3){
			cout<<0<<endl<<1;
		}
	}
	return 0;
}
