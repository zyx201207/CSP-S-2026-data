#include <bits/stdc++.h>
#define int long long
using namespace std;

int a , b;
string a1 , b1;
map<char , int>mp , mp2;

signed main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mp['A'] = 1;
	mp['B'] = 1;
	mp['C'] = 1;
	mp['D'] = 2;
	mp['F'] = 2;
	mp2['A'] = 1;
	mp2['B'] = 2;
	mp2['C'] = 3;
	mp2['D'] = 5;
	mp2['F'] = 6;
	cin >> a >> a1 >> b >> b1;
	if(a == b)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(a1[0] == b1[0] && a1[1] == b1[1])
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(mp[a1[2]] == mp[b1[2]])
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	if(abs(mp2[a1[2]] - mp2[b1[2]]) == 1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}

