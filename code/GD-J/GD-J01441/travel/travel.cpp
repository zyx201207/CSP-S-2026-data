#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2,b1,b2;
char a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> a1 >> c2 >> s2 >> a2;
	if(c1==c2)
	{
		cout << 1;
		if(s1==s2)
		{
			cout << 1;
			b1=a1-'D', b2=a2-'D';
			if(b1/abs(b1)==b2/abs(b2))
			{
				cout << 1;
				if(abs(b1-b2)==1)
					cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
