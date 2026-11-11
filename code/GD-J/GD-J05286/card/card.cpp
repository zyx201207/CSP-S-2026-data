#include <bits/stdc++.h>
using namespace std;
int n,m,a[10010],p[1000],b[200];
int f(int k,int x)
{
	for(int i=1;i<=k;i++)
	{
		if(a[i]==x)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int q=1;q<n;q++)
	{
		memset(p,0,sizeof(p));
		int k=0;
		for(int i=q;i<=n;i++)
		{
			int u=f(k,a[i]);
			if(u>0)
			{
				p[u]=a[i];
				k=u;
			}
			else
			{
				p[k]=a[i];
				k++;
			}
		}
		for(int i=1;i<=k;i++) 
		{
			b[p[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << b[i] << " ";
	}
} 
