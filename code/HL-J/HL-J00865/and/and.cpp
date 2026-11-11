#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	long long n,m,a[200],w,ww,ma=-99;
	cin>>n>>m;
	if(n==m)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			w=(a[1],a[i]);
		}
		cout<<w<<endl;
		return 0;
	}
	if(m==1)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			ww=max(ma,a[i]);
		}
		cout<<ww<<endl;
		return 0;
	}
	if(m==2)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if(a[i]!=a[j])
				{
					w=(a[i]&a[j]);
					if(w>ma)
					{
						ma=w;
					}
				}
			}
		}
		cout<<ma<<endl;
	}
	if(m==3)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
				{
					if(a[i]!=a[j]&&a[j]!=a[k]&&a[i]!=a[k])
					{
						w=(a[i]&a[j]&a[k]);
						if(w>ma)
						{
							ma=w;
						}
					}
				}
			}
		}
		cout<<ma<<endl;
	}
	if(m==4)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
				{
					for (int o=1;o<=n;o++)
					{
						if(a[i]!=a[j]&&a[j]!=a[k]&&a[i]!=a[k])
						{
							w=(a[i]&a[j]&a[k]&a[o]);
							if(w>ma)
							{
								ma=w;
							}
						}
					}
					
				}
			}
		}
		cout<<ma<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
  