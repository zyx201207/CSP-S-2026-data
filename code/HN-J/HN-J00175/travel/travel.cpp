#include <bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
string a,qw,b,qe,s;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> a >> qw >> b >> qe;
	if (a == b)
	{
		cout << 1;
		if (qw[0] == qe[0] && qw[1] == qe[1])
		{
			cout << 1;
			if ((qw[2] == 'C' && qe[2] == 'D') || (qw[2] == 'D' && qe[2] == 'C'))
			{
				cout << "00";
			}
			else
			{
				cout << 1;
				char c = qe[2];
				if (qw[2] == c-1 || qw[2] == c+1)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
