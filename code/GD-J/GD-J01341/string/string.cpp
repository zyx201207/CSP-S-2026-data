#include<bits/stdc++.h>
using namespace std;
long long n , k , sum;
struct node
{
	char ch;
	long long m;
}a[100010];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	scanf("%lld" , &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld" , &a[i].m);
		cin >> a[i].ch;
	}
	long long l = 1 , r = n;
	while(l < r)
	{
		if(a[l].ch != a[r].ch) 
		{
			if(a[l].m <= a[r].m)
			{
				sum += a[l].m;
				a[r].m -= a[l].m;
				l++;
			}
			else
			{
				sum += a[r].m;
				a[l].m -= a[r].m;
				r--;
			}
		}
		else
		{
			if(a[l].m <= a[r].m)
			{
				a[r].m -= a[l].m;
				l++;
			}
			else
			{
				a[l].m -= a[r].m;
				r--;
			}
		}
	}
	printf("%lld" , sum);
	return 0;
} 
