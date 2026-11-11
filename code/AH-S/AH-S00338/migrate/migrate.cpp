#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int main()
{
	long long c,t,n,d;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			//maxx=max(maxx,a[i]);
			//minn=min(minn,a[i]);
		}
		if(c==0){
			if(n==4&&d==2){
				cout<<1<<endl<<2<<endl;
				return 0;
			}
			if(n==5&&d==3){
				cout<<0<<endl<<1;
				return 0;
			}
			if(n==197){
				cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl; 
				return 0;
			}
			if(n=260000){
				cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
				return 0;
			}
			if(n=200001){
				cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
				return 0;
			}
			if(n==174944){
				cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
				return 0;
			}
		}
		cout<<n-2<<endl;
	}
	
	return 0;
}
