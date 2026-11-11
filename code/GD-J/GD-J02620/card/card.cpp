#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],tmp[N],far[N],ans[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i;
	cin >> n >> m;
	for (i=1;i<=n;i++)
	{
		cin >> a[i];
		tmp[a[i]]=i;
	}
	for (i=1;i<=n;i++)
	{
		if (tmp[a[i]]==i)
		{
			far[i]=-1;
		}
		else
		{
			far[i]=tmp[a[i]];	
		}
	}
	for (i=1;i<=n;i++)
	{
		long long id=i;
		while (id<=n)
		{
			ans[a[id]]++;
			if (far[id]!=-1)
			{
				id=far[id]+1;
			}
			else
			{
				id++;
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
