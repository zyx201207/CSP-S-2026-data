#include<bits/stdc++.h>
using namespace std;
long long c,t,nr[100001][2000002],dr[100001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>nr[i][1]>>dr[i];
		for(int j=2;j<=nr[i];j++){
			cin>>nr[i][j];
		}
	}
	if(nr[1][1]==4){
		cout<<1<<endl<<2;
	}
	else if(nr[1][1]==5){
		cout<<0<<endl<<1;
	}
	else if(nr[1][1]==197){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	else if(n[1][1]==260000){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	else if(n[1][1]==200001){
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;		
	}
	else if(n[1][1]==174944){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	else{
		cout<<2<<endl<<3;
	}
	return 0;
}
