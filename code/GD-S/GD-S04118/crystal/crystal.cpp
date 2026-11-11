#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m;
long long a[N];
long long b[N];
long long bi[N];
long long ni;
long long ans;
long long rr = 0;
int qwq(int t,int w)
{
	long long k = 0;
	if((w - t + 1) % 2 == 1)
	{
		int mid = (t + w) / 2;
		k = abs(a[w] - a[mid]) + abs(a[mid - 1] - a[t - 1]);
	}
	else
	{
		int mid = (t + w) / 2;
		k = abs(a[w] - a[mid]) + abs(a[mid - 1] - a[t - 1]);
		mid++;
		k = min(k,abs(a[w] - a[mid]) + abs(a[mid - 1] - a[t - 1]));
	}
	//cout << t << " " << w << " " << k << endl;
	return k;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] < 0)
		{
			rr = min(rr,a[i]);
		}
	}
	int ni = 0;
	sort(a + 1,a + n + 1); 
	for(int i = 1;i <= n;i++)
	{
		a[i] += abs(rr);
		if(a[i] != a[i - 1] || i == 1)
		{
			a[++ni] = a[i];
			b[ni]++;
		}
		else
		{
			b[ni]++;
		}
		ans = max(ans,b[ni]);
	}
	n = ni;
	for(int i = 1;i <= n;i++)
	{
		bi[i] = bi[i - 1] + b[i];
		a[i] = a[i - 1] + a[i] * b[i];
	}
	long long x = 1;
	for(long long i = 1;i <= n;i++)
	{
		if(x == i) continue;
		if(qwq(x,i) <= m)
		{
			ans = max(ans,bi[i] - bi[x - 1]);
			continue;
		}
		while(qwq(x,i) > m && x < i)
		{
			x++;
			if(qwq(x,i) <= m && x != i)
			{
				ans = max(ans,bi[i] - bi[x - 1]);
				
			}
		}
	}
	cout << ans;
//	cout << fixed << setprecision(2) << endl;
	return 0;
} 
