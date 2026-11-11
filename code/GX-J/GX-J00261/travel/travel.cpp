#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen ("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool ok=true;
	for (int i=0;i<2;i++) {
		if (a[i]!=c[i]) {
			ok=false;
			break;
		}
	}
	if (ok) cout<<"1";
	else {
		cout<<"0000";
		return 0;
		}
	ok=true;
	for (int j=0;j<2;j++) {
		if (b[j]!=d[j]) {
			ok=false;
			break;
		}
	}
	if (ok) cout<<"1";
	else {
		cout<<"000";
		return 0;
		}
	if ((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')) cout<<"1";
	else {
		cout<<"00";
		return 0;
		}
	if ((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D')) cout<<"1";
	else cout<<"0";
	return 0;
}
