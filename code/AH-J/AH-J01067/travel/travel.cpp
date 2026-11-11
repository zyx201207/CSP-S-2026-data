#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int a, c;
	string b;
}seat[3];
bool b1, b2, b3, b4;

int main()
{
	freopen("travel.in",  "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 1; i <= 2; i++)
	{
		string s, s1;
		cin >> seat[i].a >> s;
		seat[i].c = s[2] - 'A';
		s1 += s[0]; s1 += s[1];
		seat[i].b = s1;
	}
	
	if (seat[1].a == seat[2].a)
	{
		b1 = true;
		if (seat[1].b == seat[2].b)
		{
			b2 = true;
			if (!((seat[1].c <= 2) ^ (seat[2].c <= 2)))
			{
				b3 = true;
				if (abs(seat[1].c - seat[2].c) == 1)
					b4 = true;
			}
		}
	}
	cout << b1 ? 1 : 0;
	cout << b2 ? 1 : 0;
	cout << b3 ? 1 : 0;
	cout << b4 ? 1 : 0;
	return 0;
}
