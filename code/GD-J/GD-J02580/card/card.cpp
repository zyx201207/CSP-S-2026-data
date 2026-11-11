#include <bits/stdc++.h>
using namespace std;
bool b[500005];
int c[500005];
int s[500005];
int cnt[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[500005];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int d = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==true)
			{
				for(int k=c[a[j]];k<d;k++)
				{
					b[s[k]]=false;
				}
				d=c[a[j]];
			}
			s[d]=a[j];
			b[a[j]]=true;
			c[a[j]]=d;
			d++;
		}
		for(int j=1;j<d;j++)
		{
			cnt[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << cnt[i]<<" ";
	}
	return 0;
}
