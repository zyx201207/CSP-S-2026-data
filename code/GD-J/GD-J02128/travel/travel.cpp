#include<bits/stdc++.h>
using namespace std;

int c1,c2,x1,x2;
char s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> x1 >> s1 >> c2 >> x2 >> s2;
	if (c1==c2)
	{
		cout << 1;
		if (x1==x2)
		{
			cout << 1;
			if (s1>='D' && s2>='D' || s1<='C' && s2<='C')
			{
				cout << 1;
				if (max(s1,s2)==min(s1,s2)+1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	cout << '\n';
	return 0;
}
