#include<bits/stdc++.h>
using namespace std;
#define int long long

string c1 , s1 , c2 , s2;

signed main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin>>c1>>s1>>c2>>s2;
//	cout << c1 << endl << s1 << endl << c2 << endl << s2; 
	if (c1 == c2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1])
		cout << "1";
	else{
		cout << "000";
		return 0;
	}
	int a1 , b1;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
		a1 = 1;
	else
		a1 = 0;
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
		b1 = 1;
	else
		b1 = 0;
	if (a1 == b1) cout << "1";
	else{
		cout << "00";
		return 0;
	}
	int xa , xb;
	xa = s1[2] - 'A' , xb = s2[2] - 'A';
	if (abs(xa - xb) == 1)
		cout << "1";
	else
		cout << "0";
	return 0;
} 
