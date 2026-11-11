#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,aa,b,bb;
	cin >> a >> aa >> b >> bb;
	if (a != b)
	{
		cout << "0000";
		return 0;
	}
	else {
		cout << "1";
		if (aa.substr(0,2) != bb.substr(0,2))
		{
			cout << "000";
		}
		else
		{
			cout << "1";
			if ((int(aa[2]) >= int('A') && int(aa[2]) <= int('C')) && (int(bb[2])>= int('A') && int(bb[2]) <= int('C')))
			{
				cout << "1";
				if (aa[2] + 1 == bb[2] || aa[2] - 1 == bb[2])
				{
					cout << "1";
					return 0;
				}
				else
				{
					cout << "0";
					return 0;
				}
			}
			else if ((aa[2] == 'D' || aa[2] == 'F') && (bb[2] == 'D' || bb[2] == 'F'))
			{
				cout << "11";
				return 0 ; 
			}
			else
			{
				cout << "00";
				return 0;
			}
		}
	}
	return 0;
}
