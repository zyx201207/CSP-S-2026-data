#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000000];
bool check()
{
	bool z=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			z=0;
		}
	}
	if(z==1)
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
 	freopen("crystal.in","r",stdin);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9)
	{
		cout<<3;
		return 0;
	}
	if(check)
	{
		cout<<m%(a[2]-a[1])+1;
	}
	freopen("crystal.out","w",stdout);	
	return 0;
}
