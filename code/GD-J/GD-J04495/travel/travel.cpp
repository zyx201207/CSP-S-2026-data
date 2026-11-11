#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check_h(string x,string y ) {
	bool style = 0,style1 = 0;
	if(x[2] == 'A' || x[2] == 'B' || x[2] == 'C') {
		style = 1;
	} 
	if(y[2] == 'D' || y[2] == 'F'){
		style1 = 1; 
	}
	
	if(style && style1 ) {
		return false;
	}
	
	return true;
}
bool check_same(string x,string y) {

	if(x[2] == 'A' && y[2] == 'C') return false;
	
	if(x[2] == 'C' && y[2] == 'A') return false;
	
	return 1;
}
signed main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2) { 
		cout << "0000" << '\n';
		return 0;
	} 
	
	cout << "1";
	
	int w = s1[0] * 10 + s1[1];
	int w1 = s2[0] * 10 + s2[1];

	if(w != w1)  {
		cout << "000" << '\n';
		return 0;
	}
	cout << "1";
	
	if(!check_h(s1,s2)) {
		cout << "00" << '\n';
		return 0;
	}
	cout << "1";
	
	if(check_same(s1,s2)) {
		cout << "1";
	}else{
		cout << "1";
	}

	return 0;
}

