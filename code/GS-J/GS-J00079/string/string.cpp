#include<bits/stdc++.h>
using namespace std;
int n,ai,ans;
char ci,a[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int j;
	int cnt = 0;
	int h = 0;
	for (int i = 1;i<=n;i++)
	{
		cin >> ai >> ci;
		cnt += ai;
		for (j=1;j<=ai;j++)
		{
			a[h+j] = ci;
		}
		h += j-1;
	}
	for (int i = 1;i<=cnt/2;i++)
	{
		if (a[i] != a[cnt+1-i])
			ans+=1;
	}
	cout << ans;
	return 0;
}
