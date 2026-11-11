#include<bits/stdc++.h>
using namespace std;
long long ans=-1,n,m,a[10005],q;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ans=-1;
	for(int i=0;i<n;i++)
	{	
		q=0;
		if(m==1)
		{
			ans=max(ans,a[i]);
		}
		if(m==2)
		{	
			for(int j=i;j<n;j++)
			{
				q=a[i]&a[j+1];
				ans=max(ans,q);
			}
		}
	}
	cout<<ans;
	return 0;
 } 
