#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int lz=0;
	for(int i=1;i<=n-m;i++)
	{
		int yz;
		for(int j=i;j<=m;j++)
		{
			yz=a[j]&a[j+1];
			if(yz>lz)
			{
				lz=yz;
			}
		}
	}
	cout<<lz;
	return 0;
}