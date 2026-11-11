#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int N = 5e5 + 5;
long long a[N];
long long qzh[N]; //与最大值maxx差值的前缀和 

//双指针 

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long n, m, maxx = -(1e12 + 1);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		maxx = max(maxx, a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		qzh[i] = qzh[i - 1] + (maxx - a[i]);
	int l = 0, r = 1;
	int ans = 0;
	long long cmp = 0;
	while(r <= n)
	{
		cmp = qzh[r] - qzh[l] - (r - l) * (maxx - a[r]);
		if(cmp > m) l++;
		else if(cmp <= m)
		{
			ans = max(ans, r - l);
			r++;
		}
	}
	cout << ans << endl;
	return 0;
}
