#include <bits/stdc++.h>
using namespace std;
string c1,c2,x1,x2;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> x1 >> x2;
	if(c1==x1)
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	
	if(c1==x1&&c2[0]==x2[0]&&c2[1]==x2[1])
	{
		cout << 1;
		if((c2[2]<='C'&&x2[2]<='C')||(c2[2]>='D'&&x2[2]>='D'))
		{
			cout << 1;
			if(abs(c2[2]-'0'-(x2[2]-'0'))==1)
			{
				cout << 1;
				return 0;
			}
			else
			{
				cout << 0;
				return 0;
			}
		}
		else
		{
			cout << 0 << 0;
			return 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0;
		return 0;
	}
}
