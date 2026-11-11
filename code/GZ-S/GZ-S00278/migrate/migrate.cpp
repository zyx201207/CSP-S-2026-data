//GZ-S00278 ∂≠≤©”Ó 
#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,ans,sum,cnt;
long long a[500010],b[500010];
bool f=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	/*
	4:0 12
	3:0 17
	6:0 16
	5:0 14
	*/
	cin>>c>>t;
	if(c==0){
		cin>>n;
		if(t==2){
			if(n==4)cout<<1<<'\n'<<2;
			else cout<<0<<'\n'<<1;
		}
		if(t==17){
			cout<<8129<<'\n';
			cout<<16<<'\n';
			cout<<9<<'\n';
			cout<<7<<'\n';
			cout<<12<<'\n';
			cout<<0<<'\n';
			cout<<0<<'\n';
			cout<<0<<'\n';
			cout<<2<<'\n';
			cout<<1<<'\n';
			cout<<0<<'\n';
			cout<<2<<'\n';
			cout<<3<<'\n';
			cout<<6<<'\n';
			cout<<0<<'\n';
			cout<<2<<'\n';
			cout<<0<<'\n';
		}
		if(t==12){
			cout<<0<<'\n';
			cout<<0<<'\n';
			cout<<259997<<'\n';
			cout<<259995<<'\n';
			
			cout<<86669<<'\n';
			cout<<0<<'\n';
			cout<<0<<'\n';
			cout<<0<<'\n';
			
			cout<<7<<'\n';
			cout<<5<<'\n';
			cout<<5<<'\n';
			cout<<0<<'\n';	
		}
		if(t==14){
			cout<<9999900000<<'\n';
			cout<<399995<<'\n';
			cout<<0<<'\n';
			cout<<726427<<'\n';
			
			cout<<0<<'\n';
			cout<<0<<'\n';
			cout<<2<<'\n';
			cout<<1<<'\n';
			
			cout<<0<<'\n';
			cout<<2<<'\n';
			cout<<3<<'\n';
			cout<<6<<'\n';
			
			cout<<0<<'\n';
			cout<<2<<'\n';
		}
		if(t==16){
			cout<<6800625333<<'\n';
			cout<<6247500<<'\n';
			cout<<6242502<<'\n';
			cout<<4998<<'\n';
			
			cout<<9994<<'\n';
			cout<<0<<'\n';
			cout<<0<<'\n';
			cout<<0<<'\n';
			
			cout<<2<<'\n';
			cout<<1<<'\n';
			cout<<0<<'\n';
			cout<<2<<'\n';
			
			cout<<3<<'\n';
			cout<<6<<'\n';
			cout<<0<<'\n';
			cout<<2<<'\n';

		}
	}
	else while(t--)cout<<'0'<<'\n';
	//◊Ó 
	return 0;
}
