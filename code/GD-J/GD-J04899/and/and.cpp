#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n-m+1;i++)
	{
		int sum=a[i];
		for(int j=i;j<=i+m-1-1;j++)
		{
			sum=sum&a[j+1];
		}
		if(sum>maxx) maxx=sum;
	}
	cout<<maxx;
	return 0;
}
