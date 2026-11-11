#include <bits/stdc++.h>
using namespace std;
string h1, h2, s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> h1 >> s1 >> h2 >> s2;
	if(h1 == h2)
	{
		string t1, t2;
		t1 = s1.substr(0, 2);
		t2 = s2.substr(0, 2);
		if(t1 == t2)
		{
			char c1 = s1[2], c2 = s2[2];
			if(c1 <= 'C' and c2 <= 'C')
			{
				if(c1 == 'A' and c2 == 'C' or c1 == 'C' and c2 == 'A')
					cout << "1110" << "\n";
				else
					cout << "1111" << "\n";
			}
			else if(c1 >= 'D' and c2 >= 'D')
				cout << "1111" << "\n";
			else
				cout << "1100" << "\n";
		}
		else
			cout << "1000" << "\n";
	}
	else
		cout << "0000" << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// czy NB!!!!!
