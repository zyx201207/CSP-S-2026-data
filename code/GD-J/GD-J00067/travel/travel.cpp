#include<bits/stdc++.h>

using namespace std;

int c1, c2;
string s1, s2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	
	if (c1 == c2)
	{
		t1 = 1;
		
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			t2 = 1;
			
			if ('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C')
			{
				t3 = 1;
				
				if (abs(s1[2] - s2[2]) == 1)
				{
					t4 = 1;
				}
			}
			else if ('D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F')
			{
				t3 = 1;
				t4 = 1;
			}
		}
	}
	
	cout << t1 << t2 << t3 << t4;
	
	return 0;
}
