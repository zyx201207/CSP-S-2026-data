#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000001];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i*a[i]-a[1]-a[i]==m)
			{
				cout<<i;
			}
		}
	}
	


	

	return 0;
	
}