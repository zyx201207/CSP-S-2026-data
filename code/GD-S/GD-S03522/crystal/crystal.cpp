#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin >> n >> m;
	bool flag = true;
	cin >> a[1];
	for (int i = 2;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]!=a[i-1])	flag = false;
	}
	if (flag == true)
	{
		cout << n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i = 1;i<=n;i++)
		sum[i] = sum[i-1]+a[i];
	for (int i = 1;i<=n;i++)
	{
		int j = (i-1)/2,k2 = i,k1 = i,t=0;
		while (j!=k1 && j != k2 && j>0 && j<=i)
		{
			t++;
			if (t&1)	k1 = j;
			if (!(t&1))	k2 = j;
			if (a[i]*(i-j)-sum[i-1]+sum[j-1]<=m)	j = j*3/4;
			else	j=j*3/2;
		}
		ans = max(ans,i-j);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
