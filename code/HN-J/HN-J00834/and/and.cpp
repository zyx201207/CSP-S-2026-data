#include<bits/stdc++.h>
using namespace std;
int n,m,k=0,l;
int a[2000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		while(a[i]!=0)
		{
			a[i]/=2;
			l=l*10+a[i]%2;
		}
		a[i]=l;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			
		}
	}
	cout<<k;
	return 0;
}
