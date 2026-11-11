#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m,sum = 0,cnt = 1,ans = 1;
int cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{	
			sum += a[i] - a[j];
			if (sum <= m)
			{
				cnt++;
			}
			else
			{
				break;
			}
		}
		ans = max(ans,cnt);
		sum = 0;
		cnt = 1;
	}
	cout << ans;
	return 0;
} 
