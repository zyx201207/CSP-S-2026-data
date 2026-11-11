#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t;
	bool f;
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	t=n;
	while (t>=n-m+1)
	{
		f=1;
		for (int i=t+1;i<=n;++i)
		{
			if ((a[i]&a[t])!=0)
			{
				f=0;
			}
		}
		if (f==1&&t!=n)
		{
			++m;
		}
		--t;
	}
	cout<<a[n-m+1];
	return 0;
}
