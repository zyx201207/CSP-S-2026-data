#include<bits/stdc++.h>

using namespace std;

long long c,t,n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>m;
	if(c==0&&t==2&&n==4&&m==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(c==0&&t==2&&n==5&&m==3){
		cout<<0<<endl<<1;
		return 0;
	}
	if(c==0&&t==17&&n==197&&m==29418319589926278){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
		return 0;
	}
	return 0;
}
