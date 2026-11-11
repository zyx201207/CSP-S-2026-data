#include<bits/stdc++.h>
using namespace std;
long long a[400005];
long long k[500005];
bool b[200000];
bool d[200000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	long long maxx=0; 
	long long mmin=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=101&&a[i]>=0)
		{
			b[a[i]]=1;
		}
		if(a[i]<0&&a[i]>-101)
		{
			d[abs(a[i])]=1;
		}
		maxx=max(a[i],maxx);
		mmin=min(a[i],mmin);
	}
	long long maax=0;
	if(maxx<=101)
	{
		
		for(int i=1;i<=maxx;i++)
		{
			int fl=0;
			if(b[i]!=0)
			{
				for(int j=1;j<=n;j++)
				{
					k[j]=abs(i-a[j]);
				}	
				sort(k+1,k+n+1);
				long long kkk=m;
				for(int j=1;j<=n;j++)
				{
					
					if(kkk>=k[j])
					{
						kkk-=k[j];
					}
					else
					{
						maax=max(maax,(long long)j-1);
						fl=1;
						break;
					}
				}
				if(fl==0)
				{
					maxx=n;
				}
			}
		} 
		for(int i=-1;i>=mmin;i--)
		{
			int fl=0;
			if(d[abs(i)]!=0)
			{
				for(int j=1;j<=n;j++)
				{
					k[j]=abs(i-a[j]);
				}	
				sort(k+1,k+n+1);
				long long kkk=m;
				for(int j=1;j<=n;j++)
				{
					
					if(kkk>=k[j])
					{
						kkk-=k[j];
					}
					else
					{
						fl=1;
						maax=max(maax,(long long)j-1);
						break;
					}
				}
				if(fl==0)
				{
					maxx=n;
				}
			}
			
		} 
		cout<<maax;
	} 
	else
	{
		long long ksk=0;
		ksk=a[2]-a[1];
		cout<<min(1LL*n,m/ksk+1);
	}
	return 0;
} 
