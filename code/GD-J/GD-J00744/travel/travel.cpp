#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	string a,b;
	string c,d;
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		cout << "1";
		string r = "";
		string x = "";
		char sit1;
		char sit2;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] >= '0' && b[i] <= '9')
			{
				r += b[i];
			}
			else
			{
				sit1 = b[i];
			}
		}
		for (int i = 0; i < d.size(); i++)
		{
			
			if (d[i] >= '0' && d[i] <= '9')
			{
				x += d[i];
			}
			else
			{
				sit2 = d[i];
			}
		}
//		cout << "sit1=" << sit1 << "\n";
//		cout << "sit2=" << sit2 << "\n";
		if (r == x)
		{
			cout << "1";
			if (sit1 >= 'A' && sit1 <= 'C' &&sit2 >= 'A' && sit2 <= 'C')
			{
				cout << "1";
				if (sit1 == 'B' || sit2 == 'B')
				{
					cout << "1"; 
				}
				else cout << "0";
			}
			else if (sit1 == 'D' && sit2 == 'F'|| sit1 == 'F' && sit2 == 'D')
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
