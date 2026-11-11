#include<bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
int vis1 = 1;
int vis2 = 0;

int main() 
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) 
	{
		cout << 1;
	}
	else 
	{
		cout << "0000";
		return 0;
	}
	
	int pai1 = s1[0] + s1[1];
	int pai2 = s2[0] + s2[1];
	if (pai1 == pai2) 
	{
		cout << 1;
	}
	else 
	{
		cout << "000";
		return 0;
	}
	
	int zuo1 = s1[2] - 'A' + 1;
	int zuo2 = s2[2] - 'A' + 1;
	if ((zuo1 >= 4 && zuo2 >= 4) || (zuo1 <= 3 && zuo2 <= 3)) 
	{
		cout << 1;
	}
	else 
	{
		cout << "00";
		return 0;
	}
	
	if (zuo1 == zuo2 - 1 or zuo1 == zuo2 + 1) 
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
	}
	
	return 0;
}
