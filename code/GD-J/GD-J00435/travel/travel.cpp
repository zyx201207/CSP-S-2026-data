#include <bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
string c,s,c2,s2;
signed main() {
	IOS
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> c >> s >> c2 >> s2;
	if(c==c2) {
		cout << 1;
		if(s.substr(0,2)==s2.substr(0,2)) {
			cout << 1;
			if((s[2]>='D'&&s2[2]>='D')||(s[2]<='C'&&s2[2]<='C')) {
				cout << 1;
				if(abs(s[2]-s2[2])==1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
