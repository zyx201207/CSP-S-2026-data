#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a[0]==c[0] && a[1]==c[1])
	{
		if(b[0]==d[0] && b[1]==d[1])
		{
			if(b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C')
			{
				if(b[2]=='A' && d[2]=='B')
				{
					cout << "1111";
				}
				else if(d[2]=='A' && b[2]=='B')
				{
					cout << "1111";
				}
				else if(b[2]=='B' && d[2]=='C')
				{
					cout << "1111";
				}
				else if(d[2]=='B' && b[2]=='C')
				{
					cout << "1111";
				}
				else cout << "1110";
			}
			else if(b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F')
			{
				cout << "1111";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}
