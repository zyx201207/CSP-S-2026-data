#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2 ,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if(c1 != c2){
		cout << b1 << b2 << b3 << b4 << endl;
		return 0;
	}
	else b1 = 1;
	string s11 = s1.substr(0, 2);
	string s22 = s2.substr(0, 2);
	if(s11 != s22){
		cout << b1 << b2 << b3 << b4 << endl;
		return 0;
	}
	else b2 = 1;
	if((s1[2] >= 'D' && s2[2] <= 'C') || (s2[2] >= 'D' && s1[2] <= 'C')){
		cout << b1 << b2 << b3 << b4 << endl;
		return 0;
	}
	else b3 = 1;
	if(s1[2] == 'F')s1[2] = 'E';
	if(s2[2] == 'F')s2[2] = 'E';
	if(s1[2] != s2[2] + 1 && s1[2] != s2[2] - 1){
		cout << b1 << b2 << b3 << b4 << endl;
		return 0;
	}
	else b4 = 1;
	cout << b1 << b2 << b3 << b4 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
