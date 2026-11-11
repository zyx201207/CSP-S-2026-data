#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m-i;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	cout<<a[n];
	return 0;
}
