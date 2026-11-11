#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> c2 >> s1 >> s2;
	int zuoc = 0,zuos = 0,paic = 0,pais = 0;
	if(c1 == s1)
	{
		cout << "1";
		for(int i = 0;i < s2.size();i++)
		{
			if(s2[i] >= '0'&&s2[i] <= '9')
			{
				pais *= 10;
				pais += s2[i] - '0';
			}
			else
			{
				zuos += s2[i] - 'A' + 1;
			}
		}
		for(int i = 0;i < c2.size();i++)
		{
			if(c2[i] >= '0'&&c2[i] <= '9')
			{
				paic *= 10;
				paic += c2[i] - '0';
			}
			else
			{
				zuoc += c2[i] - 'A' + 1;
			}
		}
		if(paic == pais)
		{
			cout << "1";
			if((zuoc >= 1&&zuoc <= 3&&zuos >= 1&&zuos <= 3)||(zuoc >= 4&&zuoc <= 6&&zuos >= 4&&zuos <= 6))
			{
				cout << "1";
				if((zuoc == 1&&zuos == 2)||(zuoc == 2&&zuos == 3)||(zuoc == 4&&zuos == 6)||(zuos == 1&&zuoc == 2)||(zuos == 2&&zuoc == 3)||(zuos == 4&&zuoc == 6))
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
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
