#include <bits/stdc++.h>
using namespace std;

const string sits[]={"AB", "BC", "DF", "BA", "BC", "FD"};

bool mp[256][256];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string s="ABC", t="DF";
	for(int i=0;i<3;++i) {
		for(int j=0;j<3;++j) {
			if(i==j) continue;
			mp[s[i]][s[j]]=1;
		}
	}
	for(int i=0;i<2;++i) {
		for(int j=0;j<2;++j) {
			if(i==j) continue;
			mp[t[i]][t[j]]=1;
		}
	}
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {cout<<1;}
	else {
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0, 2)==s2.substr(0, 2)) {cout<<1;}
	else {
		cout<<"000";
		return 0;
	}
	if(mp[s1[2]][s2[2]]) {cout<<1;}
	else {
		cout<<"00";
		return 0;
	}
	bool flag=0;
	for(string s:sits) {
		if(s1[2]==s[0] && s2[2]==s[1]) {
			flag=1;
			break;
		}
	}
	cout<<flag; 
	return 0;
}
