#include<bits/stdc++.h>
using namespace std;

queue<int> a;
int n,m;
int l[300005],ans[300005],p[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<=n; i++)cin >> p[i];
	p[0] = 0;
	for(int j = 1; j<=n; j++)
	{
		for(int i = j; i<=n; i++)
		{
			if(p[i] != p[i-1])
			{
				ans[p[i-1]]++;
			}
			else
			{
				p[i] = 0;
			}
		}
	}
	for(int i = 1; i<=m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
