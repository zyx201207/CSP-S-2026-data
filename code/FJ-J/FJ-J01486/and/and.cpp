#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int b=30;~b;b--)
	{
		int t=ans|(1<<b);
		int c=0;
		for(int i=0;i<n;i++)
		{
			if((a[i]&t)==t)
			{
				c++;
			}
			
		}
		if(c>=m)
			{
				ans=t;
			}
	}
	cout<<ans;
	return 0;
}

