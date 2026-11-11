#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
int n,m;
long long maxn=0;
int main(void)
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
		cin>>a[i];
	}
	if(m==1)
	{
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			maxn=max(maxn,sum);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int o=i+1;o<n;o++)
			{
				sum=sum&a[o];
				maxn=max(maxn,sum);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==3)
	{
		
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int o=i+1;o<n;o++)
			{
				sum=sum&a[o];
				for(int p=o;p<n;p++)
				{
					sum=sum&a[p];
					maxn=max(maxn,sum);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==4)
	{
		
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int o=i+1;o<n;o++)
			{
				sum=sum&a[o];
				for(int p=o;p<n;p++)
				{
					sum=sum&a[p];
				    for(int d=p;d<n;d++)
					{
						sum=sum&a[d];
						maxn=max(maxn,sum);	
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==5)
	{
		
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int o=i+1;o<n;o++)
			{
				sum=sum&a[o];
				for(int p=o;p<n;p++)
				{
					sum=sum&a[p];
					for(int s=p;s<n;s++)
					{
						sum=sum&a[s];
						for(int h=s;h<n;h++)
						{
							sum=sum&a[h];
							maxn=max(maxn,sum);
						
						}
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==6)
	{
		
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int o=i+1;o<n;o++)
			{
				sum=sum&a[o];
				for(int p=o;p<n;p++)
				{
					sum=sum&a[p];
					for(int s=p;s<n;s++)
					{
						sum=sum&a[s];
						for(int d=s;d<n;d++)
						{
							sum=sum&a[d];
							for(int h=d;h<n;h++)
							{
								sum=sum&a[h];
								maxn=max(maxn,sum);
							}
						}
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==7)
	{
		
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int o=i+1;o<n;o++)
			{
				sum=sum&a[o];
				for(int p=o;p<n;p++)
				{
					sum=sum&a[p];
					for(int s=p;s<n;s++)
					{
						sum=sum&a[s];
						for(int d=s;d<n;d++)
						{
							sum=sum&a[d];
							for(int f=d;f<n;f++)
							{
								sum=sum&a[f];
								for(int h=f;h<n;h++)
								{
									sum=sum&a[h];
									maxn=max(maxn,sum);
								}
							}
						}
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==8)
	{
		
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int o=i+1;o<n;o++)
			{
				sum=sum&a[o];
				for(int p=o;p<n;p++)
				{
					sum=sum&a[p];
					for(int s=p;s<n;s++)
					{
						sum=sum&a[s];
						for(int d=s;d<n;d++)
						{
							sum=sum&a[d];
							for(int f=d;f<n;f++)
							{
								sum=sum&a[f];
								for(int g=f;g<n;g++)
								{
									sum=sum&a[g];
									for(int h=g;h<n;h++)
									{
										sum=sum&a[h];
										maxn=max(maxn,sum);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
