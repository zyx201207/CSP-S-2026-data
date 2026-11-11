#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string yn = "0000";
	if (c1 == c2)
	{
		yn[0] = '1';
		
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			yn[1] = '1';
			
			if (
				((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
				|| ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))
			)
			{
				yn[2] = '1';
				
				if (s1[2] == 'B' || s2[2] == 'B' || s1[2] == 'D' || s2[2] == 'D')
				{
					yn[3] = '1';
				}
				
			}
		}
	}
	cout << yn << '\n';
	
	return 0;
}
