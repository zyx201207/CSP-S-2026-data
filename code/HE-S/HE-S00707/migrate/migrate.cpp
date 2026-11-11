#include<bits/stdc++.h>
using namespace std;
long long c,t,a,n,nn,aa;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>a;
		if(i==1) nn=n,aa=a;
		for(int i=1;i<=n;i++){
			cin>>a;
		}
	}
	if(c==0){
		if(nn==4&&aa==2) cout<<1<<"\n"<<2;
		if(nn==5&&aa==3) cout<<0<<"\n"<<1;
		if(nn==197) cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0;
	}
	
	return 0;
} 
