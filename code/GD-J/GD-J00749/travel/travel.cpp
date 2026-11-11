#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
//#define int long long

const int N = 1e2 + 10;
string c1,c2,s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag1 = (c1 == c2 ? 1 : 0);
	bool flag2 = ((s1.substr(0,2) == s2.substr(0,2)) ? 1 : 0);
	string p1 = s1.substr(2),p2 = s2.substr(2);
	char a1 = p1[0],b1 = p2[0];
	if (a1 == 'F') a1 = 'E';
	if (b1 == 'F') b1 = 'E';
	bool flag3 = ((a1 <= 'C' && b1 <= 'C') || (a1 >= 'D' && b1 >= 'D'));
	bool flag4 = (abs(a1 - b1) == 1);
	cout << flag1 << (flag1 & flag2) << (flag1 & flag2 & flag3) << (flag1 & flag2 & flag3 & flag4) << endl;
	return 0;
}
