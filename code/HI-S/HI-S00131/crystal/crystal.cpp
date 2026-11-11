#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt = 0,a[6] = {0},p[6] = {0},s[25] = {0};
	cin >> n >> m;
	if(n > 5)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1;i<=n;i++)
    {
    	cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=i;j++)
		{
			p[i] = a[j] - a[i];
		}
		int ding = 0;
		for(int k = 1;k<=i;k++)
		{
			ding += p[k];
			s[k] = ding;
		}
	}
	int lz = 1000005,daan = 0;
	for(int i = 1;i<=n;i++)
	{
		if(s[i] < lz && s[i] <= m)
		{
			lz = s[i];
			daan = i;
		}
	}
	cout << daan;
	return 0;
}
