#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

string s1 , s2;
int a1 , a2;

int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> a1 >> s1 >> a2 >> s2;
	if(a1 == a2)
	{
		cout << 1;
		int tmp1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		int tmp2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		if(tmp1 == tmp2)
		{
			cout << 1;
			bool p1 = 0 , p2 = 0; 
			if(s1[2] == 'D' || s1[2] == 'F')
			{
				p1 = 1;
			}
			if(s2[2] == 'D' || s2[2] == 'F')
			{
				p2 = 1;
			}
			if(p1 == p2)
			{
				cout << 1;
				char c2 = (char)(s2[2] - 1);
				s2[2] = (char)(s2[2] + 1);
				if(s1[2] == c2 || s1[2] == s2[2])
					cout << 1;
				else
					cout << "0";
			}
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	
	
	return 0;
}
