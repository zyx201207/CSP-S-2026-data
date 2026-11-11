#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int y=a[1];
	for(int i=2;i<=m;i++)
	{
		y=(y&a[i]);
	}
	cout<<y;
	return 0;
}
