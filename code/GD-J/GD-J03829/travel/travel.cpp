#include <bits/stdc++.h>
#define int long long
using namespace std;
int sz[305];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	sz['A'] = sz['B'] = sz['C'] = 1;
	sz['D'] = sz['F'] = 2;
	if (c1 == c2)
	{
		cout << 1;
		string t1 = "",t2 = "";
		t1 += s1[0];
		t1 += s1[1];
		t2 += s2[0];
		t2 += s2[1];
		if (t1 == t2)
		{
			cout << 1;
			if (sz[s1[2]] == sz[s2[2]])
			{
				cout << 1;
				int temp = abs(s1[2]-s2[2]);
				if ((sz[s1[2]] == 1) && (temp == 1))
					cout << 1;
				else if (sz[s1[2]] == 2)
					cout << 1;
				else
					cout << 0;
			}
			else
				cout <<"00";
		}
		else
			cout << "000";
	}	
	else
	{
		cout << "0000";
	}
	return 0;
} 
