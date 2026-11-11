#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		a[i]=a[i]||a[i+1];
	}
	cout<<a[i];
	return 0;
}
