#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string c1,s1,c2,s2; 
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << "0000" << endl;
		return 0;
	}
	cout << "1";
	if (s1[0] != s2[0] || s1[1] != s2[1]){
		cout << "000" << endl;
		return 0; 
	}
	cout << "1";
	if ((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C')){
		cout << "00" << endl;
		return 0;
	}
	cout << "1";
	if (abs(s1[2] - s2[2]) != 1){
		cout << "0" << endl;
		return 0;
	}
	cout << "1" << endl;
	return 0;
}
