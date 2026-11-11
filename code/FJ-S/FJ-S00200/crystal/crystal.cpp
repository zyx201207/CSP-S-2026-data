#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
long long n, m, a[MAXN], num[MAXN], maxn = 0;

void solve(long long s)
{
	auto cnt = upper_bound(a + 1, a + n + 1, s);//找第一个大于 s 的
	
	long long pre = cnt - a - 1;
	memset(num, 0, sizeof(num));
	for(auto i = 1; i <= pre; i++)
	{ 
		num[i] = num[i - 1] + s - a[i];
	}
	
	unsigned long long ans = 0;
	for(auto i = 1; i <= pre; i++)
	{
		if(pre - i + 1 <= maxn) break;
		
		if(num[pre] > m) 
		{
			num[pre] =num[pre] - num[i] + num[i - 1];
		 } 
		else{
			maxn = max(maxn, pre - i + 1);
			break;
		 }
	}
	
}

int main()
{	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	long long l = 0x3f3f3f3f, r = 0;
	cin >> n >> m;
	bool q = 0, qq = 0;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if(a[i] != i) q = 1;
		if(i != 1 && a[i] != a[i - 1] + 2) qq = 1;
		l = min (l, a[i]);
		r = max (r, a[i]);
	}
	
	if(m == 0) 
	{
		cout << 1;
		return 0;
	}
	
	if(!q) //特殊性质 A 
	{
		long long i;
		for(i = 1 ; i <= m; i++)
		{
			if(i * (i + 1) / 2 > m)
			{
				i--;
				break;
			}
		 } 
		 
		cout << min(n, i + 1);
		return 0;
	}
	
	if(!qq) //特殊性质 B 
	{
		int i;
		for(i = 1 ; i <= m; i++)
		{
			if( i * i > m)
			{
				i--;
				break;
			}
		 } 
		cout << i + 1;
		return 0;
	 } 
	
	sort(a + 1, a + n + 1);
	
	for(long long i = l; i <= r; i++)
	{
		solve(i);
	}
	cout << maxn;
	return 0;
}
