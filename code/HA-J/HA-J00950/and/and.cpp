#include<bits/stdc++.h>
using namespace std;

int a[1000],b[1000],t,t1;
int main()
{
	freopen("can.in","r",stdin);
	freopen("can.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=2;i++)
	{
		while(a[i])
		{
			b[i]=a[i]%2;
			a[i]/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t=max(a[i],a[j])-min(a[i],a[j]);
			t1=max(t,t1);
		}
	}
	cout<<t1;
	return 0;
}
