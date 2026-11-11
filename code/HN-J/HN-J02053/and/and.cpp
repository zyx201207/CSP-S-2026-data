#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);//²¹È« 
	int m,n;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int ans = -1;
	for(int i = 1;i <= n - m + 1;i++)
	{
		
		for(int j = i + 1;j <= n - m + 2;j++ )
		{
			int k = a[i];
			int o = a[j];
			for(int k = j + 1;k <= j + m-2;k++)
			{
				o = o & a[k];
			}
			k = k & o;
			if(k > ans)
			{
				ans = k;
			}
		}
	}
	cout << ans; 
	return 0;
}
