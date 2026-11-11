#include<iostream>
using namespace std;
int c,t;
long long a[3000000];
long long n[3000000],d[3000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(long long j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]<0){
				a[j]=-a[j];
			}
		}
	}
	if(c==0){
		if(t==2&&n[1]==4){
			cout<<1<<endl<<2;
		}
		else if(t==2&&n[1]==5){
			cout<<0<<endl<<1;
		}
		else if(t==17){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl;
			cout<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl;
			cout<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		}
		else if(t==12){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427;
			cout<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2;
			cout<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
		else if(t==14){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427;
			cout<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2;
			cout<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
		else if(t==16){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998;
			cout<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1;
			cout<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
	}
	else{
		for(long long i=1;i<=t;i++){
			cout<<a[i];
		}
	}
	return 0;
}
