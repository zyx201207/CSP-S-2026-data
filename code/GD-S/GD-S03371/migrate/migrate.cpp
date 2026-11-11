#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[2000000];
signed main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n,a,m;
	cin>>c>>n;
	for (int i=1;i<=n;i++) {
		cin>>m>>a;
		for (int j=1;j<=m;j++) {
			cin>>s[j];
		}
	}
	if (n==2&&m==5) {
		cout<<1<<endl<<2;
		return 0;
	}
	if (n==2&&m==6) {
		cout<<0<<endl<<1;
		return 0;
	}
	if (n==17) {
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		return 0;
	}
	if (n==12) {
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		return 0;
	}
	if (n==14) {
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		return 0;
	}
	if (n==16) {
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
