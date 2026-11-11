#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n,m;
	string r,x;
	cin >> n >> r >> m >> x;
	char rpai[3] = {0};
	char xpai[3] = {0};
	for(int i = 0;i <= 2;i++)
	{
		rpai[i] = r[i];
		xpai[i] = x[i];
	}
	if(n == m)
	{
		cout << 1;
		if(rpai[0] == xpai[0] && rpai[1] == xpai[1])
		{
			cout << "1";
			if(rpai[2] == 'A')
			{
				if(xpai[2] == 'B')
				{
					cout << "11";
				}
				else if(xpai[2] == 'C')
				{
					cout << "10";
				}
				else
				{
					cout << "00";
				}
			}
			else if(rpai[2] == 'B')
			{
				if(xpai[2] == 'A' || xpai[2] == 'C')
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
			}
			else if(rpai[2] == 'C')
			{
				if(xpai[2] == 'B')
				{
					cout << "11";
				}
				else if(xpai[2] == 'A')
				{
					cout << "10";
				}
				else
				{
					cout << "00";
				}
			}
			else if(rpai[2] == 'D')
			{
				if(xpai[2] == 'F')
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
				if(xpai[2] == 'D')
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
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
