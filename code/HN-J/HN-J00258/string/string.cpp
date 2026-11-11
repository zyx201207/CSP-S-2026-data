#include<bits/stdc++.h>
using namespace std;
long long p[200010]; 
char m[200010];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string s;
	long long t,ans = 0;
	scanf("%lld",&t);
	for (int i = 0;i < t;i++)
	{
		cin >> p[i] >> m[i];
	}
	long long j = 1,cnt = 0;
	for (long long i = 0;i < t/2;)
	{
		if (cnt != i)
		{
			cnt = i;
			j = 1;
		}
		if (m[i] != m[t-i-j] && p[t-i-j] != 0 && p[i] != 0)
		{
			if (p[i] > p[t-i-j])
			{
				ans += p[t-i-j];
				p[i] -= p[t-i-j];
				p[t-i-j] = 0;
				j++;
			}
			else if (p[i] == p[t-i-j])
			{
				ans += p[i];
				p[i] = p[t-i-j] = 0;
				i++;
			}
			else
			{
				ans += p[i];
				p[i-i-j] -= p[i];
				p[i] = 0;
				i++;
			}
		}
		else
		{
			i++;
		}
		cnt = i;
	}
	printf("%lld",ans);
	return 0;
}
