#include <iostream>
#include <cstring>
using namespace std;
int n,m,a[500005],t[500005],r[500005],s[500005],ans[500005],l[500005];
bool f;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			ans[a[i-1]]=i-1;
		}
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int j=l[a[i]];
		if(j<n)
		{
			ans[1]++;
			ans[2]++;
		}
		else
		{
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]<a[i-1])
		{
			f=1;
		}
		if(s[a[i]])
		{
			r[s[a[i]]]=i;
		}
		s[a[i]]=i;
	}
	if(!f)
	{
		solve();
		return 0;
	}
	if(m==2)
	{
		solve2();
		return 0;
	}
	for(int k=1;k<=n;k++)
	{
		memset(t,0,sizeof(t));
		for(int i=k;i<=n;i++)
		{
			if(r[i])
			{
				i=r[i]-1;
			}
			else t[a[i]]++;
		}
		for(int i=1;i<=m;i++)
		{
			if(t[i])
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
