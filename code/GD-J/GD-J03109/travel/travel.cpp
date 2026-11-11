#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define int long long
string c1, s1, c2, s2;

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000" << endl;
		return 0;
	}
	cout << "1";
	char s3 = s1[2], s4  = s2[2];
	if(s1[0] != s2[0] || s1[1] != s2[1])
	{
		cout << "000" << endl;
		return 0;
	}
	cout << "1";
	if(s3 > s4) swap(s3, s4);
	if(s3 <= 'C' && s4 >= 'D'){
		cout << "00";
		return 0;
	}
	cout << "1";
	if((s3 == 'A' && s4 == 'B') || (s3 == 'B' && s4 == 'C') || (s3 == 'D' && s4 == 'F'))
	{
		cout << "1" << endl;
		return 0;
	}
	cout << "0" << endl;
}
