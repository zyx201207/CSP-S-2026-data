//GZ-J00104 贵州省瓮安第二中学 严云涵 
#include <bits/stdc++.h>
using namespace std;
long long a[200005],maxx[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			maxx[2]=max(maxx[2],a[i] & a[j]);
			for (int x=j+1;x<=n;x++)
			{
				maxx[3]=max(maxx[3],a[i]&a[j]&a[x]);
				for (int y=x+1;y<=n;y++)
				{
					maxx[4]=max(maxx[4],a[i]&a[j]&a[x]&a[y]);
				}
			}
		}
	}
	cout << maxx[m];
	return 0;
}
