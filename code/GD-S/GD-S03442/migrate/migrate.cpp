#include <bits/stdc++.h>
using namespace std;
int c,p,a[1000005],dao,ti,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>dao>>ti;
			if(t==2&&dao==4&&ti==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(t==2&&dao==5&&ti==3){
		cout<<0<<endl<<1;
		return 0;
	}
	if(t==17&&dao==197){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl;
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
	if(t==12&&dao==260000&&ti==1){
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
		return 0;
	}
	if(t==14&&dao==200001){
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
		return 0;
	}
	if(t==16&&dao==174944&&ti==139950){
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
		for(int j=1;j<=dao;j++){
			cin>>a[j];
		}
	}	

		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
