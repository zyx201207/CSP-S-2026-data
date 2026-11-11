#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	e = b[0]+b[1];
	f=d[0]+d[1];
	bool flag1,flag2;
	if (b[2] == 'A'||b[2] == 'B'||b[2] == 'C')
		flag1 = 0;
	else
		flag1 = 1;
	if (d[2] == 'A'||d[2] == 'B'||d[2] == 'C')
		flag2 = 0;
	else
		flag2 = 1;
	int cnt1 = b[2]-'A'+1,cnt2 = d[2]-'A'+1;
	if (b[2] == 'F')
		cnt1 = 5;
	if (d[2] == 'F')
		cnt2 = 5;
	if (a == c)
	{
		if (e == f)
		{
			if(flag1==flag2)
			{
				if (abs(cnt1-cnt2) == 1)
				{
					cout << "1111";
				}
				else
					cout << "1110";
			}
			else
				cout << "1100";
		}
		else
		{
			cout << "1000";
		}
	}
	else
		cout << "0000";
	return 0;
}
