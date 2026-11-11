#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[35],c[200005],ans = 0;
bool cmp(long long x,long long y)
{
	return x > y;
}
stack <int> q;
int f(int k)
{
    int t = k;
    int cnt = 0;
    while (t > 0)
    {
		t /= 2;
		cnt++;
	}
	while (k > 0)
    {
    	if (k % 2 == 0)
		{
			q.push(0);
		}
		else
		{
			q.push(1);
		}
		k /= 2;
	}
	for (int i = cnt;i >= 1;i--)
	{
		b[i] = q.top();
		q.pop();
	}
	for (int i = 1;i <= cnt;i++)
	{
		return b[i];
	}
	return 0;
}
int h(int w,int v)
{
	if(w == v)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int aa(r)
{
	int num = 1;
	for (int i = cnt;i > 0;i--)
	{
		num *= 2;
	}
	return num;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i < m;i++)
	{
		while(cnt > 0)
		{
			ans += h(f(a[i]),f(a[i + 1])) * aa(cnt);
		}
	}
	cout << ans;
	return 0;
}
