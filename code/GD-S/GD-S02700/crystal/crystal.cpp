#include<bits/stdc++.h>
using namespace std;

long long c[500010] = {0}; 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	bool flag = true;
	scanf("%lld",&n);
	scanf("%lld",&m);
	//cin >> n >> m;
	long long cha = 0;
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld",&c[i]);
		//cin >> c[i];
		if(i == 2) cha = c[2] - c[1];
		if(i >= 3 && c[i] - c[i - 1] != cha) flag = false;
	}
	
	if(flag)
	{
		long long total = 0;
		for(long long i = 1;i <= n;i++)
		{
			total += c[i];
		}
		if(m >= total)
		{
			cout << n << endl;
			return 0;
		}
		else
		{
			long long i = 1;
			long long sum = (cha + cha * i) * i / 2;
			while(sum <= m)
			{
				sum = (cha + cha * i) * i / 2;
				i++;
			}
			cout << i - 1 << endl;
			return 0;
		}
	}
	
	sort(c + 1,c + n + 1);
	long long ans = 0;
	for(long long i = n;i >= 1;i--)
	{
		long long j = i;
		long long sum = 0;
		long long score = m;
		while(score >= c[i] - c[j] && j >= 1)
		{
			score -= c[i] - c[j];
			sum++;
			j--;
		}
		ans = max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}
