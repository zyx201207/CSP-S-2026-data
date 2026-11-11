#include <iostream>
using namespace std;

int c1,c2,p1,p2;
char z1,z2;
string s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	p1 = (s1[0]-'0')*10+(s1[1]-'0');
	p2 = (s2[0]-'0')*10+(s2[1]-'0');
	z1 = s1[2];
	z2 = s2[2];
	cout << p1 << " " << z1 << " " << p2 << " " << z2 << endl;
	if(c1 == c2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(c1 == c2 && p1 == p2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (c1 == c2 && p1 == p2 && (z1 >= 'A' && z1 <= 'C' && z2 >= 'A' && z2 <= 'C') || ((z1 == 'D' || z1 == 'F') && (z2 == 'D' || z2 == 'F')))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (c1 == c2 && p1 == p2 && ((z1 >= 'A' && z1 <= 'C' && z2 >= 'A' && z2 <= 'C') || ((z1 == 'D' || z1 == 'F') && (z2 == 'D' || z2 == 'F'))) && (z1+1 == z2 || z2+1 == z1))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
} 
