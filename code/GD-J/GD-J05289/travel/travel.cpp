#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string c1, c2, s1, s2;
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	
	if(c1 == c2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	
	string ss1 = {}, ss2 = {};
	ss1 += s1[0];
	ss2 += s2[0];
	ss1 += s1[1];
	ss2 += s2[1];
	if(ss1 == ss2) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	
	char R = s1[2], X = s2[2];
	if(R + X == 'D' + 'F'){
		cout << "11";
		return 0;
	}
	if(R + X == 'B' + 'C'){
		cout << "11";
		return 0;
	}
	if(R + X == 'A' + 'B'){
		cout << "11";
		return 0;
	}
	if(R + X == 'A' + 'C'){
		cout << "10";
		return 0;
	}
	cout << "00";
	return 0;
}
