#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			mmax=max(mmax,a[i]);
		}
		cout<<mmax<<endl;
		return 0;
	}
	else if(m==2)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int k=a[i]&a[j];
				mmax=max(mmax,k);
			}
		}
		cout<<mmax;
		return 0;
	}
	else if(m==3)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					int k=a[i]&a[j]&a[l];
					mmax=max(mmax,k);
				}
				
			}
		}
		cout<<mmax;
		return 0;
	}
	else if(m==4)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					for(int t=l+1;t<=n;t++)
					{
						int k=a[i]&a[j]&a[l]&a[t];
						mmax=max(mmax,k);
					}
					
				}
				
			}
		}
		cout<<mmax;
		return 0;
	}
	else if(m==5)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					for(int t=l+1;t<=n;t++)
					{
						for(int y=t+1;y<=n;y++)
						{
							int k=a[i]&a[j]&a[l]&a[t]&a[y];
						mmax=max(mmax,k);
						}
						
					}
					
				}
				
			}
		}
		cout<<mmax;
		return 0;
	}
	else if(m==6)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					for(int t=l+1;t<=n;t++)
					{
						for(int y=t+1;y<=n;y++)
						{
							for(int z=y+1;z<=n;z++)
							{
								int k=a[i]&a[j]&a[l]&a[t]&a[y]&a[z];
								mmax=max(mmax,k);
							}
							
						}
						
					}
					
				}
				
			}
		}
		cout<<mmax;
		return 0;
	}
	else if(m==7)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					for(int t=l+1;t<=n;t++)
					{
						for(int y=t+1;y<=n;y++)
						{
							for(int z=y+1;z<=n;z++)
							{
								for(int x=z+1;x<=n;x++)
								{
									int k=a[i]&a[j]&a[l]&a[t]&a[y]&a[z]&a[x];
								mmax=max(mmax,k);
								}
								
							}
							
						}
						
					}
					
				}
				
			}
		}
		cout<<mmax;
		return 0;
	}
	else if(m==8)
	{
		int mmax=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					for(int t=l+1;t<=n;t++)
					{
						for(int y=t+1;y<=n;y++)
						{
							for(int z=y+1;z<=n;z++)
							{
								for(int x=z+1;x<=n;x++)
								{
									for(int g=x+1;g<=n;g++)
									{
										int k=a[i]&a[j]&a[l]&a[t]&a[y]&a[z]&a[g];
									mmax=max(mmax,k);
									}
									
								}
								
							}
							
						}
						
					}
					
				}
				
			}
		}
		cout<<mmax;
		return 0;
	}
	return 0;
}
