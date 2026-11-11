#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0,max=-1,a[20005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		s=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			s=s&a[i];
		}
	}
	if(m=1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>max)
				max=a[i];
		}
		s=max;
	}
	cout<<s;
	return 0;
}
