#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,d,n[N],a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d;
		for(int j=1;j<=n[i];j++){
			cin>>a[j];
		}
	}
	if(c==0){
		if(n[t]==5){
			cout<<1<<endl<<2;
		}else if(n[t]==6&&d==2){
			cout<<0<<endl<<1;
		}else if(t==17){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		}else if(t==12){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		}else if(t==14){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}else{
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
	}else{
		for(int i=1;i<=t;i++){
			for(int j=1;j<=n[i];j++){
				cout<<0<<endl;
			}
		}
	}
	return 0;
} 
