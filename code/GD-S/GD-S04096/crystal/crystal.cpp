#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],f[500010];
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for (int i=1;i<=n;i++)
	{
		int x=m;
		for (int j=i-1;j<=1;j--)
		{
			if (x>a[i]-a[j])
			{
				x-=a[i]-a[j];
				f[i]++;
			}
			else
			{
				break;
			}
		}
	}
	sort(f,f+n+1);
	cout<<f[n];
	return 0;
}


