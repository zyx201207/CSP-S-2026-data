#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,maxx=-999999999;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>maxx)
			{
				maxx=a[i];
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>maxx)
				{
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==3)
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=k+1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if((a[k]&a[i]&a[j])>maxx)
					{
						maxx=a[k]&a[i]&a[j];
					}
				}
			}			
		}
		cout<<maxx;
		return 0;
	}
	else if(m==4)
	{
		for(int x=1;x<=n;x++)
		{
			for(int k=x+1;k<=n;k++)
			{
				for(int i=k+1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						if((a[x]&a[k]&a[i]&a[j])>maxx)
						{
							maxx=a[x]&a[k]&a[i]&a[j];
						}
					}
				}			
			}	
		}
		cout<<maxx;
		return 0;
	}
	else if(m==5)
	{
		for(int y=1;y<=n;y++)
		{
			for(int x=y+1;x<=n;x++)
			{
				for(int k=x+1;k<=n;k++)
				{
					for(int i=k+1;i<=n;i++)
					{
						for(int j=i+1;j<=n;j++)
						{
							if((a[y]&a[x]&a[k]&a[i]&a[j])>maxx)
							{
								maxx=a[y]&a[x]&a[k]&a[i]&a[j];
							}
						}
					}			
				}	
			}			
		}
		cout<<maxx;
		return 0;
	}
	else if(m==6)
	{
		for(int q=1;q<=n;q++)
		{
			for(int y=q+1;y<=n;y++)
			{
				for(int x=y+1;x<=n;x++)
				{
					for(int k=x+1;k<=n;k++)
					{
						for(int i=k+1;i<=n;i++)
						{
							for(int j=i+1;j<=n;j++)
							{
								if((a[y]&a[x]&a[k]&a[i]&a[j])>maxx)
								{
									maxx=a[y]&a[x]&a[k]&a[i]&a[j];
								}
							}
						}			
					}	
				}			
			}			
		}

		cout<<maxx;
		return 0;
	}
	else if(m==7)
	{
		for(int w=1;w<=n;w++)
		{
			for(int q=w+1;q<=n;q++)
			{
				for(int y=q+1;y<=n;y++)
				{
					for(int x=y+1;x<=n;x++)
					{
						for(int k=x+1;k<=n;k++)
						{
							for(int i=k+1;i<=n;i++)
							{
								for(int j=i+1;j<=n;j++)
								{
									if((a[y]&a[x]&a[k]&a[i]&a[j])>maxx)
									{
										maxx=a[y]&a[x]&a[k]&a[i]&a[j];
									}
								}
							}			
						}	
					}			
				}			
			}			
		}
		cout<<maxx;
		return 0;
	}
	else if(m==8)
	{
		for(int e=1;e<=n;e++)
		{
			for(int w=e+1;w<=n;w++)
			{
				for(int q=w+1;q<=n;q++)
				{
					for(int y=q+1;y<=n;y++)
					{
						for(int x=y+1;x<=n;x++)
						{
							for(int k=x+1;k<=n;k++)
							{
								for(int i=k+1;i<=n;i++)
								{
									for(int j=i+1;j<=n;j++)
									{
										if((a[y]&a[x]&a[k]&a[i]&a[j])>maxx)
										{
											maxx=a[y]&a[x]&a[k]&a[i]&a[j];
										}
									}
								}			
							}	
						}			
					}			
				}			
			}			
		}
		cout<<maxx;
		return 0;
	}
	else if(m==9)
	{
		for(int r=1;r<=n;r++)
		{
			for(int e=r+1;e<=n;e++)
			{
				for(int w=e+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int y=q+1;y<=n;y++)
						{
							for(int x=y+1;x<=n;x++)
							{
								for(int k=x+1;k<=n;k++)
								{
									for(int i=k+1;i<=n;i++)
									{
										for(int j=i+1;j<=n;j++)
										{
											if((a[y]&a[x]&a[k]&a[i]&a[j])>maxx)
											{
												maxx=a[y]&a[x]&a[k]&a[i]&a[j];
											}
										}
									}			
								}	
							}			
						}			
					}			
				}			
			}			
		}
		cout<<maxx;
		return 0;
	}
	else if(m==10)
	{
		for(int t=1;t<=n;t++)
		{
			for(int r=t+1;r<=n;r++)
			{
				for(int e=r+1;e<=n;e++)
				{
					for(int w=e+1;w<=n;w++)
					{
						for(int q=w+1;q<=n;q++)
						{
							for(int y=q+1;y<=n;y++)
							{
								for(int x=y+1;x<=n;x++)
								{
									for(int k=x+1;k<=n;k++)
									{
										for(int i=k+1;i<=n;i++)
										{
											for(int j=i+1;j<=n;j++)
											{
												if((a[y]&a[x]&a[k]&a[i]&a[j])>maxx)
												{
													maxx=a[y]&a[x]&a[k]&a[i]&a[j];
												}
											}
										}			
									}	
								}			
							}			
						}			
					}			
				}			
			}			
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}

