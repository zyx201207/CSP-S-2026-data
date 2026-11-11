#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005],f[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)	cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		int l=i,x[5005],y[1005];
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		x[a[l]]=1;
		y[a[l]]=1;
		while(l<n)
		{
			l++;
			if(y[a[l]]==1)
			{
				for (int j = x[a[l]];j <= l-1;j++)	y[a[j]]=0;
				x[a[l]]=l;
				y[a[l]]=1;
			}
			else
			{
				x[a[l]]=l;
				y[a[l]]++;
			}	
		}
		for (int j = 1;j <= m;j++)	
		{
			f[j]+=y[j];
		}
	}
	for (int i = 1;i <= m;i++)	cout << f[i] << ' ';
	return 0;
}
