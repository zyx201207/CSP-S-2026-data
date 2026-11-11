#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int aa,ab,ba,bb;
	char ac,bc;
	cin >> aa >> ab >> ac >> ba >> bb >> bc;
	if(aa==ba)
	{
		if(ab==bb)
		{
			if(((ac == 'B' || ac == 'C' || ac == 'A')&&(bc == 'B' || bc == 'C' || bc == 'A')) || ((ac=='D' || ac=='F') && (bc=='F' || bc=='D')))
			{
				if((ac=='A' && bc=='B') || (bc=='A' && ac=='B') || (bc=='c' && ac=='B') || (bc=='B' && ac=='C') || (bc=='D' && ac=='F') || (bc=='F' && ac=='D'))
				{
					cout << "1111";
				    return 0;
				}
				else
				{
					cout << "1110";
				    return 0;
				}
			}
			else
			{
				cout << "1100";
			    return 0;
			}
		}
		else
		{
			cout << "1000";
		    return 0;
		}
	}
	else
	{
		cout << "0000";
		return 0;
	}
}
