#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sb=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int n=(a[i]&a[i+1]);
		if(n>sb)
		{
			sb=n;
		}
	}
	cout<<sb;
	return 0;
}
