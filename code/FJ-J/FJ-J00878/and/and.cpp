#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1e9,b=-1e9;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b=max(b,a[i]);
	}
	if(m=1)
	{
		cout<<b;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	
	cout<<ans;
	return 0;
 } 
