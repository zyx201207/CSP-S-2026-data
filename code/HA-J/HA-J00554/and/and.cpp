#include<bits/stdc++.h>
using namespace std;
int a[11000];
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
	int max;
	max=a[1];
	for(int i=1;i<=n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
		else
		{
			a[i]=a[i]
		}
	}
	return 0;
}
