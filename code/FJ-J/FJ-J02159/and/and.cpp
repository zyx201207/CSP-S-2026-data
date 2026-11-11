#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200010]={0},x,y;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int c=0;
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j])
			{
				c++;
			}
		}
		if(x<=c)
		{
			if(x==c)
			{
				y=max(y,a[i]);
			}
			else
			{
				y=a[i];
			}
			x=c;
		}
	}
	cout<<y;
}
