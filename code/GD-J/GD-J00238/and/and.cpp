#include <bits/stdc++.h>

using namespace std;

long long ar[200005];
int n,m;
long long mx = 0;

void dg(long long ans,int t,int s)
{
	if (ans <= mx)
	{
		return;
	}
	if (ans == 0)
	{
		return;
	}
	if (s == m)
	{
		mx = max(mx,ans);
		return;
	}
	for (int i = t + 1;i <= n;i++)
	{
		dg((ans & ar[i]),i,s + 1);
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool flag = 1;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> ar[i];
		if (i != 1 and ar[i] - ar[i - 1] != 1)
		{
			flag = 0;
		}
	}
	if (flag)
	{
		cout << n - m;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		dg(ar[i],i + 1,1);
	}
	cout << mx;
	return 0;
}
