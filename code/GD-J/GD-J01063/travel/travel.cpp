#include<bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	int a, b, c, d;
	a = (s1[1]-'0')+(s1[0]-'0')*10;
	b = (s2[1]-'0')+(s2[0]-'0')*10;
	c = (s3[1]-'0')+(s3[0]-'0')*10;
	d = (s4[1]-'0')+(s4[0]-'0')*10;
	if(a == c)
	{
		cout << "1";
		if(b == d)
		{
			cout << "1";
			int h = s2[2]-'A'+1, w = s4[2]-'A'+1;
			if(h == 6) h = 5;
			if(w == 6) w = 5;
			if((h >= 4 && w >= 4) || (h <= 3 && w <= 3))
			{
				cout << "1";
				if(h-w == 1 || w-h == 1)
				{
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else
		{
			cout << "000";
		}
	}
	else cout << "0000";
	
	return 0;
}
