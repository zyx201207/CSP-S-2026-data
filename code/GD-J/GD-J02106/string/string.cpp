#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005], ar[600000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long ans=0;
	long long cnt=0;
	int j = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		cnt += a[i];
		for (; j <= a[i]; j++)
		{
			ar[i]=c[i];
		}
	}
	if(cnt%2==0)
	{
		
		int i = 1, k = cnt;
		for (;i<=cnt/2;)
		{
			if(ar[i]!=ar[k])
			{
				ans++;
			}
			i++;
			j--;
		}
	}
	cout << ans;
	return 0;
}
