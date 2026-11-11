#include <bits/stdc++.h>
using namespace std;
int a[500005],sum[300005];
stack <int> card;
bool flag[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if(!flag[a[j]])
			{
				flag[a[j]] = true;
				card.push(a[j]);
			}
			else
			{
				while(true)
				{
					if(card.top() != a[j])
					{
						card.pop();
					}
					else
					{
						card.pop();
						card.push(a[j]);
						break;
					}
				}
			}
		}
		while(!card.empty())
		{
			sum[card.top()]++;
			card.pop();
		}
		for(int j = 1;j <= m;j++)
		{
			flag[j] = false;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << sum[i] << " ";
	}
	return 0;
}
