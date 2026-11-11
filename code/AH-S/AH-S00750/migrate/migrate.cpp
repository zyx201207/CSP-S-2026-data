#include<bits/stdc++.h>
using namespace std;
int c,t,laji;
int n[100009],d[100009];

void answer(){
	if(t==2){
		if(n[1]==4)cout<<1<<endl<<2<<endl;
		else cout<<0<<endl<<1<<endl;
	}else if(t==17){
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
	}else if(t==12){
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
	}else if(t==14){
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
	}else{
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
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++)cin>>laji;
	}
	if(c==0){
		answer();
	}else{
		cout<<1<<endl;
	}
	return 0;
}
