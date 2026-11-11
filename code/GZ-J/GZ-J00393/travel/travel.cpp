#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
string ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	map<char,int>a;
	a['A'] = 1;
	a['B'] = 1;
	a['C'] = 1;
	a['D'] = 2;
	a['F'] = 2;
	map<char,int>o;
	o['A'] = 1;
	o['B'] = 2;
	o['C'] = 3;
	o['D'] = 4;
	o['F'] = 5;
	if(c1 == c2) {
		ans += '1';
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			ans += '1';
			if(a[s1[2]] == a[s2[2]]) {
				ans += '1';
				if(s1[0] == s2[0] && s1[1] == s2[1]) {
//				cout<<s1[2]<<" "<<s2[3]<<o[s1[3]]<<" "<<o[s2[3]];
					if(o[s1[2]] + 1 == o[s2[2]] || o[s1[2]] - 1 == o[s2[2]]) {
						ans += '1';
					} else {
						ans += '0';
					}
				} else {
					ans+='0';
				}
			} else {
				ans+="00";
			}
		} else {
			ans +="000";
		}

	} else {
		ans = "0000";
	}
	cout<<ans;
	return 0;
}






