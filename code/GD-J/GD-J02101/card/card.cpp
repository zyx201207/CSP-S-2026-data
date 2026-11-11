#include <iostream>
using namespace std;
int n,m,a[500005],p[500005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int f = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] > a[i - 1]) f = 0;
		p[a[i]] = i;
	}
	if(f)
	{
		for(int i = 1;i <= m;i++) ans[i] += p[i];
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			int k = i;
			while(k <= n)
			{
				ans[a[k]]++;
				k = p[a[k]] + 1;
			}
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
