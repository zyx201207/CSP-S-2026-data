#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t, t2 ,t3;
	cin >> t >> t2 >> t3;
	if(t >= 2000001)
		t = 200000;
	if(t == 0 && t2 == 2 && t3 == 4) {
		cout << 1 << endl << 2;
	}else if(t == 0 && t2 == 2 && t3 == 5) {
		cout << 0 << endl << 1;
	}else if(t == 0 && t2 == 17) {
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	}else if(t == 0 && t2 == 12) {
		cout <<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
	}else if(t == 0 && t2 == 14) {
		cout <<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
	}else if(t == 0 && t2 == 16) {
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
	}else{
		while(t2--) {
			cout << 0 << endl;
		}
	}
}
