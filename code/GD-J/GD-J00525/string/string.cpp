#include <bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	char ch;
}a[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long sum = 0;
	bool flag = true;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i].num);
		sum += a[i].num;
		cin>>a[i].ch;
		if(i != 0 && a[i].ch != a[i - 1].ch)
		{
			flag = false;
		}
	}
	if(n == 1 || flag)
	{
		printf("0");
		return 0;
	}
	if(n == 2)
	{
		if(a[0].num == a[1].num)
		{
			printf("0");
		}
		else
		{
			printf("%d",min(a[0].num,a[1].num));
		}
		return 0;
	}
	long long ans = 0;
	for(int i = 0,j = n - 1;i < j && j >= 0 && i < n;i++,j--)
	{
		if(a[i].num == a[j].num && a[i].ch == a[j].ch)
		{
			continue;
		}
		if(a[i].num == a[j].num && a[i].ch != a[j].ch)
		{
			ans += a[i].num;
		}
		else
		{
			ans += max(a[i].num,a[j].num);
			if(a[i].num < a[j].num)
			{
				a[i].num += a[j].num - a[i].num;
				a[i + 1].num -= a[j].num - a[i].num;
			}
			else
			{
				a[j].num += a[i].num - a[j].num;
				a[j - 1].num -= a[i].num - a[j].num;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
