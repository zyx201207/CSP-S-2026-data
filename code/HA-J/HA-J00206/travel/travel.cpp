#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int s11 = s1[0] + s1[1] - 96,s21 = s2[0] + s2[1] - 96;
	int s12 = s1[2],s22 = s2[2];
	bool s13,s23;
	if(s12 - 65 <= 2) s13 = 1;
	else s13 = 0;
	
	if(s22 - 65 <= 2) s23 = 1;
	else s23 = 0;
	
	
	if(c1 != c2) cout << "0000" ;
	else{
		cout << "1";
		if(s11 != s21) cout << "000";
		else
		{
			cout << "1";
			if(s13 != s23) cout << "00";
			else
			{
				cout << "1";
				if(abs(s12 - s22 ) == 1)
					cout << "1";
				else cout << "0";
			}
		}
	}
	return 0;
}
