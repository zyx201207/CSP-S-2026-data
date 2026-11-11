#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if(s1 != s2) cout << "0000";
	else{
		cout << '1';
		if(c1[0] == c2[0] && c1[1] == c2[1])
		{
			cout << '1';
			if((c2[2] - '0' <= 19 && c1[2] - '0' <= 19) || (c2[2] - '0' > 19 && c1[2] - '0' > 19))
			{
				cout << '1';
				if(abs(c1[2] - c2[2]) == 1) cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	}
	return 0;
 } 
