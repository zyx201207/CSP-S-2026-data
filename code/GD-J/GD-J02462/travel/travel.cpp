#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4; 

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3)
	{
		cout << "1";
		if(s2[0] == s4[0] && s2[1] == s4[1])
		{
			cout << "1";
			char c1 = s2[2],c2 = s4[2];
			if('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C')
			{
				cout << "1";
				if(abs(int(c1) - int(c2)) == 1)	cout << "1" << endl;
				else	cout << "0" << endl;
			}
			else if('D' <= c1 && c1 <= 'F' && 'D' <= c2 && c2 <= 'F')
			{
				cout << "1";
				if(abs(int(c1) - int(c2)) == 1)	cout << "1" << endl;
				else	cout << "0" << endl;
			}
			else	cout << "00" << endl;
		}
		else	cout << "000" << endl;
	}
	else	cout << "0000" << endl;
	return 0;
}
