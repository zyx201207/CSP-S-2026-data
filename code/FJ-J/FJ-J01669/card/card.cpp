#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005],mm;
bool d;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
		if(mm>a[i])d=1;
	
		mm=a[i];
	}
	if(!d)
	{
		for(long long i=1;i<=m;i++)
	{
		long long ans=0;
		for(long long j=b[i]-1;j>0;j--)
		{
			if(a[j]==i)
			{
				break;
			}
			if(j<b[a[j]]&&b[i]<b[a[j]])
			{  
			   bool s=0;
			   for(long long k=j-1;k>0;k--)
			   {
			   	if(a[k]==i)
			    {
			    	s=1;
				break;
			    }
			   }
			   if(!s)
			   {
			   	ans=j;
			   	break;
			   }
				
			}
		}
		cout<<b[i]-ans<<" ";
	}
	}
	else for(long long i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}