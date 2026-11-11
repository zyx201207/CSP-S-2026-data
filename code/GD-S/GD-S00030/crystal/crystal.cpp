#include<bits/stdc++.h>
using namespace std;
long long n, m,a[500005],b[500005],sum;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n <= 5000 && m <= 1000005)
	{
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		for(int i = 1; i <= n; i++)
		{
			b[i] = a[i] - a[i-1];
		}
		long long sum1 = 0;
		for(int i = 1; i <= n; i++)
		{
			long long sum = 0, cnt = 1, maxn = 1;
			for(int j = i+1; j <= n; j++)
			{
				if(sum + b[j] * cnt <= m){
					sum += b[j] * cnt;
					maxn++;
					cnt++;
					}
				else
				{
					break;
				}
			}
			sum1 = max(maxn, sum1);
		}
		cout <<  sum1;
	}
	
	else
	{
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		long long sum = 0, cnt = 1, cnt1 = 1,maxn = 1;
		for(int j = 1; j <= n; j++)
		{
			if(sum + cnt1 * cnt <= m){
				sum += cnt1 * cnt;
				maxn++;
				cnt++;
				}
			else
			{
				break;
			}
		}
		
		cout <<  maxn;
	}
	return 0;
}
