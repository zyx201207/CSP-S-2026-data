#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,b[500005],maxn = LLONG_MIN,cnt,pp;
int main()
{
	// 快读 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// 主代码 
	cin>>n>>m;
	for (long long i = 1;i <= n;i++)
	{
		cin>>a[i];
		l = min(l,a[i]);
		r = max(r,a[i]);
	} // 确定水晶能量的值域 
	sort(a + 1,a + n + 1);
	for (long long i = l;i <= r;i++)
	{
		cnt = 0,pp = m;
		for (long long j = 1;j <= n;j++) b[j] = a[j];
		for (long long j = n;j >= 1;j--)
		{
			if (b[j] < i && abs(i - b[j]) <= pp)
			{
				pp -= abs(i - b[j]);
				b[j] = i;
			}
			if (b[j] == i) cnt++;
		}
		maxn = max(maxn,cnt); 
	} // i代表希望用尽可能多的能量值为i的水晶参与合成 
	cout<<maxn;
	return 0;
}
// 感觉不像那么简单的样子 
