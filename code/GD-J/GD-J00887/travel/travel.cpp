#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout<<"1";
		string pa1 = s1.substr(0,2);
		string pa2 = s2.substr(0,2); 
		if(pa1 == pa2) {
			cout<<"1";
			char c1 = s1[2], c2 = s2[2];
			if(c1 == 'F' || c1 == 'D') {
				if(c2 == 'F' || c2 == 'D')
				cout<<"11";
				else cout<<"00";
			}
			else if(c2 != 'F' && c2 != 'D' && c1 != 'F' && c1 != 'D') {
				cout<<"1";
				if(abs(c2 - c1) == 1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
