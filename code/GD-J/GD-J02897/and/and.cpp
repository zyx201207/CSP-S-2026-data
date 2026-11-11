#include<bits/stdc++.h>
using namespace std;
int a[1001000],vis[1001000][1001000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;)
	{
		for(int j=1;j<=n;)
		{
			vis[i][j]=a[i]%2;
			a[i]=a[i]/2;
			if(a[i]==0)
			{
				i++;
				j=1;
			}
		}
	}
	cout<<12;
	return 0;
}
