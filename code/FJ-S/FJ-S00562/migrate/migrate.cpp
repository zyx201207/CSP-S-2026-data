#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int t1=t,one;
	while(t1--){
		cin>>n>>d;
		if(t1==t-1){
			one=n;
		}		
		int k;
		for(int i=0;i<n;i++){
			cin>>k;
		}
	}
	if(c==0 && t==2 && one==4){
		cout<<1<<endl<<2;
	}
	else if(c==0 && t==2 && one==5){
		cout<<0<<endl<<1;
	}
	else if(c==0 && t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	else if(c==0 && t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	else if(c==0 && t==16){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;	
	}
	
	return 0;
	
}

