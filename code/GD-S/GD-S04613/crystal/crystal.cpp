#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,tt,id;
int a[500005],cnt[5005],tag[5005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >>n >> m;
	if (n <= 5005)
	{
		tt = 1;
		for (int i = 1;i <= n;i ++)
		{
			cin >> a[i];
			for (int j = 1;j <i;j ++)
			{
				if (a[i] == a[j])
				{
					cnt[i]++;
					if (cnt[i]>=tt)
					{
						tt = cnt[i];
						id = a[i];
					}
				}
			}		
		}
		sort(a+1,a+n+1);
		if (tt == 1)
		{
			if (n % 2 == 0)
			{
				id = a[n/2];
			}
			else
			{
				id = a[n/2+1];
			}
		} 
		for (int i = 1;i <= n;i ++)
		{
			if (a[i] <= id) tag[i] = id - a[i];
		}
		sort(tag+1,tag+n+1);
		for (int i = 1;i <= n;i ++)
		{
			if (tag[i] == 0) continue;
			if (m >= tag[i])
			{
				tt ++;
				m -= tag[i];
			}
		}
		cout << tt;
	}
	else
	{
		for (int i = 1;i <= n;i ++)
		{
			cin >> a[i];
		}
		if (a[2] >= a[1]) tt = a[2]-a[1];
		else tt = a[1] - a[2];
		int t = tt;
		int ans = 1;
		int flag = 0;
		while(m>=tt)
		{
			if (tt == 0) 
			{
				flag = 1;
				break;
			}
			ans ++;
			m -= tt;
			tt += t;
		}
		if (flag == 1) cout << n;
		else cout << ans;
	}
	return 0;
}
