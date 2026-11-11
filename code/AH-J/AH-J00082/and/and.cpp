#include<cstdio>
#include<iostream>
using namespace std;
long long n;
long long m;
int a[200010];
long long ans,flag=1,id;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	int max=-1;
	for (int i=1;i<=m;++i)
	{
		max=-1;
		for (int j=0;j<n;++j)
		{
			if (max<a[j])
			{
				max=a[j];
				id=j;
			}
		}
		a[id]=-1;
		if (flag==1)
		{
			ans=max;
			flag=0;
		}
		else
		{
			ans=ans&max;
		}
	}
	cout<<ans;
	return 0;
 } 
