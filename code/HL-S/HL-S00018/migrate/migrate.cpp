#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int b[100000000];
int main()
{
	int c,n,ans=0;
	cin>>c>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			cin>>a[j];
			z=a[j]-a[j-1];
		}
		
		for(int j=1;j<=x;j++)
		{
			if(y>=z*2&&y<=(n/2+1)*z)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
