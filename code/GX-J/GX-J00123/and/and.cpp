#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int maxn=a[0]&a[1];
	for (int j = 0; j < n; ++j)
	{
		if (a[j]&a[j+1]>maxn)
		{
			maxn=a[j]&a[j+1];
		}
	}
	cout<<maxn;
	return 0;
}
