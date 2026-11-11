#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1 ;
		string t1 ;
		t1 = s1[0] + s1[1];
		string t2 ;
		t2 = s2[0] + s2[1];
		if(t1 == t2)
		{
			cout << 1;
			char x1 = s1[2];
			char x2 = s2[2];
			int n1 = x1 - 'A' + 1 , n2 = x2 - 'A' + 1;
			if((n1 > 3 && n2 > 3) || (n1 <= 3 && n2 <= 3))
			{
				cout << 1 ;
				if(abs(n1 - n2) == 1)
					cout <<1;
				else
					cout << 0;
			}
			else cout << "00"; 
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
} 
