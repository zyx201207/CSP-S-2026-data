#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int cnt = 0,ans = 0;
	for(int i = 2;i <= n;i++)
	{
		for(int j = 1;j < i;j++)
		{
			cnt += a[i] - a[j];
			a[j] = a[i];
		}
		if(cnt == m)
		{
			int j = i;
			while(a[j] == a[i])
				j++;
			cout << j - 1;
			return 0;
		}
		if(cnt > m)
		{
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}
