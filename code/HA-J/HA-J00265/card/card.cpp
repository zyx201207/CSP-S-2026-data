#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("strave.in","r",stdin);
	freopen("strave.out","w",stdout);
	int m,n;
	int a[300005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[n%(m+i)];
	}
	return 0;
}
