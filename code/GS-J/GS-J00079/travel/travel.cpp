#include<bits/stdc++.h>
using namespace std;
string z1z,z1a,z2z,z2a;
bool yice(string a,string b)
{
	if (a[2] <= 'C' && (b[2] <= a[2] || b[2] <= 'C'))
	{
		return 1;
	}
	return 0;
}
bool yice2(string x, string y)
{
	if ((x[2] == 'D' && y[2] == 'F') || (x[2] == 'F' && y[2] == 'D'))
		return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> z1z >> z1a >> z2z >> z2a;
	if (z1z == z2z)
	{
		cout << '1';
	}
	else cout << '0';
	if (z1z == z2z && z1a[0] == z2a[0] && z1a[1] == z2a[1])
	{
		cout << '1';
	}
	else cout << '0';
	if (z1z == z2z && z1a[0] == z2a[0] && z1a[1] == z2a[1] && (yice(z1a,z2a) || yice2(z1a,z2a)))
	{
		cout << '1';
	}
	else cout << '0';
	if (z1z == z2z && z1a[0] == z2a[0] && z1a[1] == z2a[1] && (yice(z1a,z2a) || yice2(z1a,z2a)) && ((yice(z1a,z2a) && abs(z1a[2] - z2a[2]) == 1) || yice2(z1a,z2a)))
		cout << '1';
	else cout << '0';
	return 0;
}
