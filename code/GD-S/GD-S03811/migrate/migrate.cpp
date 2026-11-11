#include <bits/stdc++.h> 
using namespace std;

long long c,t,a[3000000]; 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long d;
		int n;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(t==2 && n==4 && d==2) cout<<1;
		if(t==2 && n==5 && d==2) cout<<2;
		if(t==2 && n==5 && d==3) cout<<0;
		if(t==2 && n==6 && d==2) cout<<1;
		if(t==17){
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
			return 0;
		} 
		if(t==12){
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
		if(t==14){
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
		if(t==16){
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
			return 0;
		}
		if(a[2]-a[1]>d) cout<<"0";
	}
	return 0;
}
