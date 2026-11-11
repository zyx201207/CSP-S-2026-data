#include <iostream>
#include <string>
using namespace std;

bool chk(char a,char b)
{
	if (a <= 'C' && b <= 'C') return 1;
	if (a > 'C' && b > 'C') return 1;
	return 0;
 } 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	cout << 1;
	if (s1.substr(0,2) != s2.substr(0,2))
	{
		cout << "000";
		return 0;
	}
	cout << 1;
	if (!chk(s1[2],s2[2])) 
	{
		cout << "00";
		return 0;
	}
	cout << 1;
	if (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1 || (s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F')) cout << 1;
	else cout << 0;
	return 0;
 } 
