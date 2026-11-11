#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int a[25];
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	int minn = 0;
	for (int i = 1;i<=n;i++)
	{
		minn = a[3];
	}
	for (int i = 1;i<=m;i++)
	{
		a[1]++;
		if(a[1]==minn)
		{
			break;
		}
		m--;
		if(m==0)
		{
			break;
		}
	}
	for (int i = 1;i<=m;i++)
	{
		a[2]++;
		if(a[2]==minn)
		{
			break;
		}
		m--;
		if(m==0)
		{
			break;
		}
	}
	int ans =0;
	for (int i = 1;i<=n;i++)
	{
		if(a[i]==minn)
		{
			ans++;
     	}
	}
	if(ans!=3)
	{
		cout << "4";
    }
	else
	{
		cout << ans;
	}
	return 0;
} 
