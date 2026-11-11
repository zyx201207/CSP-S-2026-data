#include <bits/stdc++.h>
using namespace std;
struct card
{
	int num;
	bool check;
};
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n ,m;
	scanf("%lld %lld", &n, &m);
	long long i;
	int j,k;
	vector<struct card> a;
	vector<int>cc;
	struct card b;
	b.check = 1;
	for(i = 0;i < n;n++)
	{
		scanf("%d", &j);
		b.num = j;
		a.push_back(b);
		for(j = 0;j < n;j++)
		{
			if(a[j].num == a[i].num && a[j].check)
			{
				for(k = j;k < i;k++)
				{
					a[k].check = 0;
				}
			}
		}
	}
	cc.push_back(0);
	for(i = 1;i <= m;i++)
	{
		cc.push_back(0);
	}
	for(i = 0;i < n;i++)
	{
		if(a[i].check)
		{
			cc[a[i].num]++;
		}
	}
	for(i = 1;i <= m;i++)
	{
		printf("%d ",cc[i]);
	}
	return 0;
}
