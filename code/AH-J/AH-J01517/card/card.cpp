#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f=1;
	cin>>n>>m;
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a[0]=a[1];
	if(f==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				cout<<i-1<<" ";
			}
		}
	}
	return 0;
}
