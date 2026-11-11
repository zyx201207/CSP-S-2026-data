#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    bool a = 0;
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	int b = r2[2] + x2[2];
	if(r1 == x1)
	{
		cout<<'1';
		if(r2[1] == x2[1])
		{
			cout<<'1';
			if(r2[2] == 'A' || r2[2] == 'B' || r2[2] == 'C')
			{
				if(x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C')
				{
					cout<<'1';
					a = 1;
				}
				else
				{
					cout<<'0'<<'0';
				}
			}
			else if(r2[2] == 'D' || r2[2] == 'F')
			{
				if(x2[2] == 'D' || x2[2] == 'F')
				{
					cout<<'1';
					a = 1;
				}
				else
				{
					cout<<'0'<<'0';
				}
			}
			else
			{
				cout<<'0'<<'0';
			}
		}
		else
		{
			cout<<'0'<<'0'<<'0';
		}
	}
	else
	{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	if(a == 1)
	{
		if(b == 131)
		{
			cout<<'1';
		}
		else if(b == 133)
		{
			cout<<'1';
		}
		else if(b == 138)
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
