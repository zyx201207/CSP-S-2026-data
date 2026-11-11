#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string c;
	string d;
	cin >> a >> b >> c >> d;
	if(a!=c)
	{
		cout << "0000";
	}
	else
	{
		cout << '1';
		int n = b.size();
		int m = d.size();
		char q = b[n-1];
		char w = d[m - 1];
		b.erase(n-1,1);
		d.erase(m-1,1);
		if(b!=d)
		{
			cout << "000";
		}
		else
		{
			cout << '1';
			if(((q=='A'||q=='B'||q=='C')&&(w=='D'||w=='F'))||((w=='A'||w=='B'||w=='C')&&(q=='D'||q=='F')))
			{
				cout << "00";
			}
			else
			{
				cout << '1';
				int o = abs(q-w);
				if(o==1)
				{
					cout << '1';
				}
				else
				{
					cout << '0';
				}
			}
		}
	}
	
	return 0;
}
