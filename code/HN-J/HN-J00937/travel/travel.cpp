#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c1>> s1>> c2>> s2;
	int d1 = (s1[0] - '0') * 10 + s1[1] - '0';
	int d2 = (s2[0] - '0') * 10 + s2[1] - '0';
	char id1 = s1[2];
	char id2 = s2[2];
	if(c1 != c2){
		cout << "0000";
		return 0;
	}else{
		cout << '1';
	}
	if(d1 != d2){
		cout << "000";
		return 0;
	}else{
		cout << '1';
	}
	if(((id1 == 'A' || id1 == 'B' || id1 == 'C') && (id2 == 'A' || id2 == 'B' || id2 == 'C')) || ((id1 == 'D' || id1 == 'F') && (id2 == 'D' || id2 == 'F'))){
		cout << '1';
	}else{
		cout << "00";
		return 0;
	}
	if((id1 == 'A' && id2 == 'B') || (id1 == 'B' && id2 == 'A') || (id1 == 'C' && id2 == 'B') || (id1 == 'B' && id2 == 'C') || (id1 == 'D' && id2 == 'F') || (id1 == 'F' && id2 == 'D')){
		cout << '1';
	}else{
		cout << '0';
	}
	return 0;
} 
