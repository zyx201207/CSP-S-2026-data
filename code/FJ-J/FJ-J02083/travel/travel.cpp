#include <bits/stdc++.h>
using namespace std;
string az,bz;
int a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> az >> b >> bz;
	if (a == b)
	{
		cout << 1;
	}
	else{
		cout << 0;
	}
	if (az[0] == bz[0] && az[1] == bz[1] && a == b)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if ((az[2]  == 'D' || az[2] == 'F') && (bz[2] == 'D' || bz[2] == 'F') && a == b) cout <<1;
	else if ((az[2] != 'D' && az[2] != 'F') && (bz[2] != 'D' && bz[2] != 'F') && a == b) cout <<1;
	else{
		cout <<0;
	}
	if ((az[2] == 'A' && bz[2] == 'B') || (az[2] == 'B' && (bz[2] == 'A' || bz[2] == 'C')) || (az[2] == 'C' && bz[2] == 'B') || (az[2] == 'D' && az[2] == 'F') || (az[2] == 'F' && bz[2] == 'D'))
	{
		if (a == b)
		{
			cout <<1;
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}
