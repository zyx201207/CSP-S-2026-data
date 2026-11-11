#include<bits/stdc++.h>
using namespace std;
long long r[100000005];
long long n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	if(n==m)
	{	int f=r[1];
		for(int i=2;i<=m;i++)
		{
			f=f&r[i];	
		}
		cout<<f;
	}
	else if(m==1)
	{	int f=-1;
		for(int i=1;i<=m;i++)
		{
			if(r[i]>=f)
			{
				f=r[i];
				}	
		}
		cout<<f;
		
	}
	if(m==2)
	{
		long long mm=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int nn=i&j;
				if(mm>nn)
				{
					mm=nn;
				}	
		}	
			}
			
		
		}
		cout<<mm;
	}
	if(m==3)
	{
		long long mm=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;j<=n;k++)
				{
				int n1=i&j&k;
					if(mm>n1)
				{
					mm=n1;
				}		
				}
				
			}
			
		
		}
		cout<<mm;
	}
	if(m==4)
	{
		long long mm=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;j<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
					int n1=i&j&k&l;
						if(mm>n1)
				{
					mm=n1;
				};	
					}
						
				}
				
			}
			
		
		}
		cout<<mm;
	}
	if(m==5)
	{
		long long mm=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;j<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int j1=l+1;j1<=n;j1++)
						{
						int n1=i&j&k&l&j1;
					if(mm>n1)
				{
					mm=n1;
				};			
						}
					
					}
						
				}
				
			}
			
		
		}
		cout<<mm;
	}
		if(m==6)
	{
		long long mm=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;j<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int j1=l+1;j1<=n;j1++)
						{
								for(int j11=l+1;j11<=n;j11++)
						{
						int n1=i&j&k&l&j1&j11;
					if(mm>n1)
				{
					mm=n1;
				};			
						}}
					
					}
						
				}
				
			}
			
		
		}
		cout<<mm;
	}
	if(m==7)
	{
		long long mm=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;j<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int j1=l+1;j1<=n;j1++)
						{
								for(int j11=l+1;j11<=n;j11++)
						{
							for(int j111=l+1;j111<=n;j111++)
						{
						int n1=i&j&k&l&j1&j11&j111;
					if(mm>n1)
				{
					mm=n1;
				};			
						}}}
					
					}
						
				}
				
			}
			
		
		}
		cout<<mm;
	}

	
	
	return 0;
}
