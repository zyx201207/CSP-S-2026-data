#include <bits/stdc++.h>
using namespace std;
int n, m,a[500005],ja[300005];
int main()
{
	//freopen("card1.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		stack<int> s;
		int ma[300005];
		for (int j =i; j <= n; j++)
		{
			if(!ma[a[j]])
			{
				s.push(a[j]);
				ma[a[j]] = 1;
			}
			else
			{
				while(s.top()!=a[j])
				{
					s.pop();
				}
			}
		}
		while(s.size())
		{
			ja[s.top()]++;
			s.pop();
		}
		for (int i= 1; i <= m; i++) cout << ja[i] << " ";
	}
	for (int i= 1; i <= m; i++) cout << ja[i] << " ";
	return 0;
}
