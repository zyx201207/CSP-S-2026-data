#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0;
	cin >> n >> m;
	int s[n+5],a[100005];
	for (int i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (s[j]>=x)
			{
				x=s[j];
			}
		}
		a[i]=x;
		x=0;
	}
	cout << a[m-1];
	return 0;
} 
