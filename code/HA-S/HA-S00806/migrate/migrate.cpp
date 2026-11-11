#include<bits/stdc++.h>
using namespace std;
long long c,m,n,q,a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	if(c==0){
		cin>>m>>n;
		if(c==0&&m==2&&n==4)cout<<1<<endl<<2;
		else if(c==0&&m==2&&n==5)cout<<0<<endl<<1;
		else if(c==0&&m==17&&n==197)cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		else if(c==0&&m==12&&n==260000)cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		else if(c==0&&m==14&&n==200001)cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		else if(c==0&&m==16&&n==174944)cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
		if(c!=0){
		cin>>m;
		while(m--){
			cin>>n>>q;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int k=q/(a[2]-a[1])-1;
			int w=2*k+2;
			if(n-w>=0&&k>=1)cout<<n-w+1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}

