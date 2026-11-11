#include <bits/stdc++.h>
using namespace std;
vector<char> strs;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	scanf("%lld", &n);
	long long i,j;
	long long sum;
	long long k;
	char things;
	long long needs = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%lld", &sum);
		getchar();
		scanf("%c", &things);
		for(j = 0;j < sum;j++)
		{
			strs.push_back(things);
		}
	}
	k = strs.size();
	for(i = 0;i < (k / 2 + 1);i++)
	{
		if(strs[i] != strs[(k-1)-i])
		{
			needs++;
		}
	}
	printf("%lld", needs);
	return 0;
}
