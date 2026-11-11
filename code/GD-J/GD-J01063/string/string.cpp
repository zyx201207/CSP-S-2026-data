#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n;
int a[N];
long long sum[N];
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum[i] = sum[i-1] + a[i];
	}
	long long cnt = 0;
	if(sum[n] % 2 == 1)
	{
		int id = 0;
		for(int i = 1; i <= n; i++)
		{
			if(sum[i-1] <= sum[n]/2+1 && sum[i] >= sum[n]/2+1)
			{
				id = i;
				break;
			}
		}
		long long mid = sum[n]/2+1;
		long long l = mid, r = mid;
		int ld = id, rd = id;
		while(l > 0)
		{
			int x = l - sum[ld-1]-1, y = sum[rd] - r;
			if(c[ld] == c[rd])
			{
				if(x == y)
				{
					l -= x+1;
					r += y+1;
					ld--;
					rd++;
				}
				else if(x < y)
				{
					l -= x+1;
					ld--;
					r += x+1;
				}
				else
				{
					r += y+1;
					rd++;
					l -= y+1;
				}
			}
			else
			{
				if(x == y)
				{
					l -= x+1;
					r += y+1;
					ld--;
					rd++;
					cnt+=x+1;
				}
				else if(x < y)
				{
					l -= x+1;
					ld--;
					r += x+1;
					cnt += x+1;
				}
				else
				{
					r += y+1;
					rd++;
					l -= y+1;
					cnt += y+1;
				}
			}
		}
	}
	else
	{
		int id1 = 0, id2 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(sum[i-1] <= sum[n]/2 && sum[i] >= sum[n]/2)
			{
				id1 = i;
				break;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(sum[i-1] <= sum[n]/2+1 && sum[i] >= sum[n]/2+1)
			{
				id2 = i;
				break;
			}
		}
		long long mid = sum[n]/2;
		long long l = mid, r = mid+1;
		int ld = id1, rd = id2;
		while(l > 0)
		{
			int x = l - sum[ld-1]-1, y = sum[rd] - r;
			if(c[ld] == c[rd])
			{
				if(x == y)
				{
					l -= x+1;
					r += y+1;
					ld--;
					rd++;
				}
				else if(x < y)
				{
					l -= x+1;
					ld--;
					r += x+1;
				}
				else
				{
					r += y+1;
					rd++;
					l -= y+1;
				}
			}
			else
			{
				if(x == y)
				{
					l -= x+1;
					r += y+1;
					ld--;
					rd++;
					cnt+=x+1;
				}
				else if(x < y)
				{
					l -= x+1;
					ld--;
					r += x+1;
					cnt += x+1;
				}
				else
				{
					r += y+1;
					rd++;
					l -= y+1;
					cnt += y+1;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
