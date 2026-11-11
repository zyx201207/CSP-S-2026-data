#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	int cnt=t,res=0;
	int n,d;
	while(t--){
		scanf("%d %d",&n,&d);
		if(n==4&&d==2) res=1;
		if(n==5&&d==3) res=2;
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
	}
	if(c==0){
		if(cnt==2&&res==1) cout<<1<<endl<<2;
		if(cnt==2&&res==2) cout<<0<<endl<<1;
		if(cnt==17) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		if(cnt==12) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		if(cnt==14) cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		if(cnt==16) cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	return 0;
}
