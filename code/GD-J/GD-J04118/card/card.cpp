#include<iostream>
#include<fstream>
using namespace std;
long long n , m , tnt = 1;
long long a[500005];
int cnts[500005] , cnts2[500005] , card[500005] , anss[500005];
int main()
{
	freopen("card1.in" , "r" , stdin);
//	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) scanf("%lld" , &a[i]);
	if(m == 2)
	{
		cout << n << " " << n;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			card[tnt++] = a[i];
			cnts[a[j]]++;
			if(cnts[a[j]] > 1)
			{
				for(int k = cnts2[a[j]];k <= tnt;k++)
				{
					cnts[card[k]] = 0;
					card[k] = 0;
				}
				tnt = cnts2[a[j]];
				cnts[a[j]] = 1;
			}
		}
		for(int j = 1;j <= m;j++) if(cnts[j] == 1) anss[j]++;
	}
	for(int i = 1;i <= m;i++) cout << anss[i] << " ";
	return 0;
}
