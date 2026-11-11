#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3)
	{
		cout << "0000";
		return 0;
	}
	cout << 1;
	if(s2[0] != s4[0] || s2[1] != s4[1])
	{
		cout << "000";
		return 0;
	}
	cout << 1;
	int p = 0, q = 0;
	if(s2[2] - 'A' < 3)p = 1;
	if(s4[2] - 'A' < 3)q = 1;
	if(p != q)
	{
		cout << "00";
		return 0;
	}
	cout << 1;
	p = s2[2] - 'A';
	q = s4[2] - 'A';
	if(abs(p - q) == 1)
		cout << 1;
	else cout << 0; 
} 
