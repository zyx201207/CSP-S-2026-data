#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],id[300005];
bool b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int x=1;
	for(int i=1;i<=n;i++)
	{
		int z;
		cin >> z;
		if(b[z])
		{
			for(int j=id[z]+1;j<x;j++)
			{
				b[z]=0;
				id[z]=0;
				
			}
			x = id[z]+1;
			a[x]=z;
		}
		else
		{
			b[z] = 1;
			id[z] = x;
			a[x] = z;
			x++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << b[i] << " " << id[i] << endl;
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		for(int j=1;j<=m;j++)
		{
			if(b[i]&&id[i]>=j)ans++;
		}
		cout << ans << " ";
	}
}
