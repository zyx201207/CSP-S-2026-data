#include <bits/stdc++.h>
using namespace std;
int main()
{	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,zd = 0;
	cin>>n>>m;
	int a[n+m+1000];
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if (m==1)
	{
		for (int i=0;i<n;i++)
		{
			if (zd<a[i])
			{
				zd = a[i];
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==2)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if ((a[i]%a[j])>zd)
				{
					zd=a[i]%a[j];
				}
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==3)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					if ((a[i]%a[j]%a[k])>zd)
					{
						zd=(a[i]%a[j]%a[k]);
						
					}
				}
				
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==4)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					for (int h=2;h<n;h++)
					{
						if ((a[i]%a[j]%a[k]%a[h])>zd)
						{
							zd=(a[i]%a[j]%a[k]%a[h]);
						}
					}
					
				}
				
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==5)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					for (int h=2;h<n;h++)
					{
						for (int g=3;g<n;g++)
						{
							if ((a[i]%a[j]%a[k]%a[h]%a[g])>zd)
							{
								zd=(a[i]%a[j]%a[k]%a[h]%a[g]);
							}
						}
						
					}
					
				}
				
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==6)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					for (int h=2;h<n;h++)
					{
						for (int g=3;g<n;g++)
						{
							for (int f=4;f<n;f++)
							{
								if ((a[i]%a[j]%a[k]%a[h]%a[g]%a[f])>zd)
								{
									zd=(a[i]%a[j]%a[k]%a[h]%a[g]%a[f]);
								}
							}
						
						}
						
					}
					
				}
				
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==7)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					for (int h=2;h<n;h++)
					{
						for (int g=3;g<n;g++)
						{
							for (int f=4;f<n;f++)
							{
								for (int d=4;d<n;d++)
								{
									if ((a[i]%a[j]%a[k]%a[h]%a[g]%a[f]%a[d])>zd)
									{
										zd=(a[i]%a[j]%a[k]%a[h]%a[g]%a[d]);
									}
								}
								
							}
						
						}
						
					}
					
				}
				
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==7)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					for (int h=2;h<n;h++)
					{
						for (int g=3;g<n;g++)
						{
							for (int f=4;f<n;f++)
							{
								for (int d=4;d<n;d++)
								{
									for (int s=5;s<n;s++)
									{
										if ((a[i]%a[j]%a[k]%a[h]%a[g]%a[f]%a[d]%a[s])>zd)
										{
											zd=(a[i]%a[j]%a[k]%a[h]%a[g]%a[d]%a[s]);
										}
									}
									
								}
								
							}
						
						}
						
					}
					
				}
				
			}
		}
		cout<<zd;
		return 0;
	}
	else if (m==8)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					for (int h=2;h<n;h++)
					{
						for (int g=3;g<n;g++)
						{
							for (int f=4;f<n;f++)
							{
								for (int d=4;d<n;d++)
								{
									for (int s=5;s<n;s++)
									{
										for (int aa=6;aa<n;aa++)
										{
											if ((a[i]%a[j]%a[k]%a[h]%a[g]%a[f]%a[d]%a[s]%a[aa])>zd)
											{
												zd=(a[i]%a[j]%a[k]%a[h]%a[g]%a[d]%a[s]%a[aa]);
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
		cout<<zd;
		return 0;
	}
	else if (m==9)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=1;k<n;k++)
				{
					for (int h=2;h<n;h++)
					{
						for (int g=3;g<n;g++)
						{
							for (int f=4;f<n;f++)
							{
								for (int d=4;d<n;d++)
								{
									for (int s=5;s<n;s++)
									{
										for (int aa=6;aa<n;aa++)
										{
											for (int t=7;t<n;t++)
											{
												if ((a[i]%a[j]%a[k]%a[h]%a[g]%a[f]%a[d]%a[s]%a[aa]%a[t])>zd)
												{
													zd=(a[i]%a[j]%a[k]%a[h]%a[g]%a[d]%a[s]%a[aa]%a[t]);
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
		cout<<zd;
		return 0;
	}
	else{
		cout<<1;
	}
	freopen(stdin);
	freopen(stdout);
	return 0;
}
