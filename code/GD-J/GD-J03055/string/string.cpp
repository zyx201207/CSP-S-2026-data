#include <bits/stdc++.h>
using namespace std;

struct node
{
	long long x;
	char c;	
};
node a[200005];
long long l[200005], r[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	long long len = 0;
	for(long long i = 1; i <= n; i++) {cin >> a[i].x >> a[i].c;l[i] = len + 1;len += a[i].x;r[i] = len;}
	long long mid = len / 2;
	long long cur = n;
	long long sum = 0;
	long long ans = 0;
	long long check = 0;
	for(long long i = 1; i <= n; i++)
	{
		long long nsum = sum + a[i].x;
		if(nsum < mid)
		{
			long long lft = len - nsum + 1;
			long long rft = len - (sum + 1) + 1;
			if(l[cur] <= rft && l[cur] >= lft)
			{
				if(a[cur].c != a[i].c)ans += rft - l[cur] + 1;
				cur--;
				while(l[cur] >= lft) {if(a[cur].c != a[i].c) ans += r[cur] - l[cur] + 1;cur--;}
				if(r[cur] >= lft) 
				{
					if(a[cur].c != a[i].c) ans += r[cur] - lft + 1;
				}
			}
			else if(l[cur] <= rft) if(a[cur].c != a[i].c)ans += rft - lft + 1;
		}
		else
		{
			long long lft = len - (len / 2) + 1;
			long long rft = len - (sum + 1) + 1;
			if(l[cur] <= rft && l[cur] >= lft)
			{
				if(a[cur].c != a[i].c)ans += rft - l[cur] + 1;
				cur--;
				while(l[cur] >= lft) {if(a[cur].c != a[i].c) ans += r[cur] - l[cur] + 1;cur--;}
				if(r[cur] >= lft) 
				{
					if(a[cur].c != a[i].c) ans += r[cur] - lft + 1;
				}
			}
			else if(l[cur] <= rft) if(a[cur].c != a[i].c)ans += rft - lft + 1;
			break;
		}
		sum = nsum;
	}
	cout << ans;
	return 0;
}
