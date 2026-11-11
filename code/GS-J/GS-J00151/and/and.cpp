#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int maxx=-1000;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((a[i]&a[j])<(a[i+1]&a[j]))
			{
				maxx=a[i+1]&a[j];
			}
			else maxx=a[i]&a[j];
		}
	}
	cout << maxx;
	return 0;
}
