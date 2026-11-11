#include <bits/stdc++.h> 
using namespace std;
int a, g, d;
int s[600005];
int jh[600005];
int jg[600005];
int num[600005];
int sta = 0;
int sm = 1;
int main()
{
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin >> a >> g;
	for(int f = 1; f <= a; f++)
		cin >> s[f];
	while(sm <= a)
	{
		for(int f = sm; f <= a; f++)
		{
			jh[sta] = s[f];
			if(jg[s[f]] == 1)
				for(int j = sta; j >= 0; j--)
				{
					if(jh[j] == s[f])
					{
						sta = j;
						jg[s[f]] = 0;
						break;
					}
					else
						jg[s[j]] = 0;
				}
			else
			{
				jg[s[f]] = 1;
				sta++;
			}
		}
		for(int f = 1; f <= sta; f++)
		{
			num[jh[f]]++;
		}
		sm++;
	}
	for(int f = 1; f <= g; f++)
	{
		cout << num[f] << " ";
	}
	return 0;
}
