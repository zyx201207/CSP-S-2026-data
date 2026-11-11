#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	char r = (char)s1[2],x = (char)s2[2];
//	cout << r << " " << x;
	if((r >= 'A' && r <= 'C' && x >= 'A' && x <= 'C') || ((r == 'D' || r == 'F') && (x == 'D' || x == 'F'))) cout << "1";
	else{
		cout << "00";
		return 0;
	}
	if(r > x) swap(r,x);
	if((r == 'A' && x == 'B') || (r == 'B' && x == 'C') || (r == 'D' && x == 'F')) cout << "1";
	else{
		cout << "0";
		return 0;
	}
	return 0;
}
