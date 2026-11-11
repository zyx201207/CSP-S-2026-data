#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 5e5 + 10;
int n, res = 0;
long long m;
long long a[SIZE] = {0};

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	
	int i = 1, j = 1;
	long long sum = 0;
	while(i <= n)
	{	
		while(sum > m)
		{
			sum -= a[i] - a[j];
			j++;
		}
		res = max(res, i - j + 1);
		i++;
		sum += (i - j) * (a[i] - a[i - 1]);
	}
	
	printf("%d", res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
