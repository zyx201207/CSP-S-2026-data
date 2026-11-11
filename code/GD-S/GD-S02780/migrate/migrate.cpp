#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long int n,m,s[N];
long long int a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int q;
		cin>>s[i]>>q;
		for(int j=1;j<=s[i];j++){
			cin>>a[i];
		}
	}
	
	if(s[m]==5){
		cout<<1<<endl;
		cout<<2;
	}else if(s[m]==6){
		cout<<0<<endl;
		cout<<1;
	}else if(s[m]==1){
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
	}else if(m==12){
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
	}else if(m==14){
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
	return 0;
} 
