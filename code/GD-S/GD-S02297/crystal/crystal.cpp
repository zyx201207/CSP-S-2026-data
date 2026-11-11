#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,cs=0,max_=0;
	cin >> n >> m;//n是水晶数，m是次数 
	int a[n+3];
	for (int i=1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i <= m;i++)
	{
		for (int j=1;j <= n;j++)
		{
			a[j]++;
			int sum=0;
			for (int l=1;l <= n;l++)
			{
				if (a[l] == a[j])
				{
					sum++;
				}
			}
			if (sum > max_)
			{
				max_=sum;
				cs=j;
			}
			a[j]--;
		}
		a[cs]++;
	}
	cout << max_;
	return 0;
}
