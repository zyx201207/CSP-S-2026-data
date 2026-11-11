#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
ll sum;

struct node
{
	ll num;
	int ls;
	int l;
	int r;
}num[200005];

bool cmp(node a,node b)
{
	return a.num > b.num;
}

ll ans = 0;

void answers(int xs)
{
	if (xs <= 0) return ;
	ll ka = (1 << (xs - 1));
	sum = 0;
	for (int i = num[0].r;i <= n;i = num[i].r)  if (num[i].num & ka) sum ++;
	if (sum >= m)
	{
		ans += ka;
		for (int i = num[0].r;i <= n;i = num[i].r)
		{
			if (!(num[i].num & ka))
			{
				num[num[i].l].r = num[i].r;
				num[num[i].r].l = num[i].l;
			}
		}	
	}
	answers(xs - 1);
	return ;
}

int main()
{
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i ++) 
	{
		scanf("%lld",&num[i].num);
		num[i].ls = int(log2(num[i].num)) + 1;
	}
	sort(1 + num,n + num + 1,cmp);
	num[0].r = 1;
	for (int i = 1;i <= n;i ++)
	{
		num[i].l = i - 1;
		num[i].r = i + 1;
	}
	num[n + 1].l = n;
	answers(num[1].ls);
	printf("%lld\n",ans);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
