// GZ-J00002 утсю╨Г 
#include <bits/stdc++.h>
using namespace std;
int a,c,b2,d2;
string b,d,b1,d1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	for(int i =0;i<2;i++)
	{
		b1 += b[i];
		d1 += d[i];
	}
	b2 = b[2];
	d2 = d[2];
	if(a == c)
	{
		cout << "1";
		if(b1 == d1)
		{
			cout << "1";
			if(b2>=65&&b2<=67&&d2>=65&&d2<=67)
			{
				cout << "1";
				if(b2+1 == d2||b2-1==d2)
				{
					cout << "1";
				else cout << "0";
				
			}
			else if(b2>=68&&b2<=70&&d2>=68&&d2<=70)
			{
				cout << "11";
			}
			else
			{
				cout << "00";
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
