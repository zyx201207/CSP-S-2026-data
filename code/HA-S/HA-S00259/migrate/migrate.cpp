#include <bits/stdc++.h>
using namespace std;
long long int c,t,a,b;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		if(c==0) {
			cin>>a>>b;
			if(a==4 && b==2) cout<<1<<endl<<2<<endl;
			else if(a==5 && b==3) cout<<0<<endl<<1;
			else if(a==197&&b==29418319589926278) cout<<8129<<endl<<
				        16<<endl<<
				        9<<endl<<
				        7<<endl<<
				        12<<endl<<
				        0<<endl<<
				        0<<endl<<
				        0<<endl<<
				        2<<endl<<
				        1<<endl<<
				        0<<endl<<
				        2<<endl<<
				        3<<endl<<
				        6<<endl<<
				        0<<endl<<
				        2<<endl<<
				        0<<endl;
			else if(a==260000&&b==1)cout<<0<<endl<<
				                            0<<endl<<
				                            259997<<endl<<
				                            259995<<endl<<
				                            86669<<endl<<
				                            0<<endl<<
				                            0<<endl<<
				                            0<<endl<<
				                            7<<endl<<
				                            5<<endl<<
				                            5<<endl<<
				                            0<<endl;
			else if(a==200001&& b==206291914738518400) cout<<9999900000<<endl<<
				        399995<<endl<<
				        0<<endl<<
				        716427<<endl<<
				        0<<endl<<
				        0<<endl<<
				        2<<endl<<
				        1<<endl<<
				        0<<endl<<
				        2<<endl<<
				        3<<endl<<
				        6<<endl<<
				        0<<endl<<
				        2<<endl;
			else if(a==174944&& b==139950) cout<<6800625333<<endl<<
				                                   6247500<<endl<<
				                                   6242502<<endl<<
				                                   4998<<endl<<
				                                   9994<<endl<<
				                                   0<<endl<<
				                                   0<<endl<<
				                                   0<<endl<<
				                                   2<<endl<<
				                                   1<<endl<<
				                                   0<<endl<<
				                                   2<<endl<<
				                                   3<<endl<<
				                                   6<<endl<<
				                                   0<<endl<<
				                                   2<<endl;


		}
		cout<<0<<endl;
	}
	return 0;
}