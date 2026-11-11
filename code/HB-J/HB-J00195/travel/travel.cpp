#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
//  check the freopen
int rc,xc,rp,xp;char rop,xop;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> rc >> rp >> rop >> xc >> xp >> xop;
	if (rc == xc)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (rp == xp)
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if (xop <= 'C' and rop <= 'C')
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	int s = xop-rop;
	if (abs(s) != 1)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	
	return 0;
}
