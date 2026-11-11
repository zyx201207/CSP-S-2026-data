#include<bits/stdc++.h>
using namespace std;
#define int long long
bool vis[200005];
int n,m,a[200005]; 
int maxn=0,al;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)
		{
			al=a[i];
		}
		else
		{
			al=al&a[i];
		}
		maxn=max(a[i],maxn);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==3)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if((i!=j)&&(i!=k)&&(j!=k))
						maxn=max(maxn,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<maxn;
		return 0;
	} 
	if(m==4)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						if((i+j+k+l)/4!=i)
							maxn=max(maxn,a[i]&a[j]&a[k]&a[l]);
		cout<<maxn;
		return 0;
	} 
	if(m==5)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						for(int ll=1;ll<=n;ll++)
							if((i+j+k+l+ll)/5!=i)
								maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[ll]);
		cout<<maxn;
		return 0;
	} 
	if(m==6)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						for(int ll=1;ll<=n;ll++)
							for(int lll=1;lll<=n;lll++)
								if((i+j+k+l+ll+lll)/6!=i)
									maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[ll]&a[lll]);
		cout<<maxn;
		return 0;
	} 
	if(m==7)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						for(int ll=1;ll<=n;ll++)
							for(int lll=1;lll<=n;lll++)
								for(int o=1;o<=n;o++)
									if((i+j+k+l+ll+lll+o)/7!=i)
										maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[ll]&a[lll]&a[o]);
		cout<<maxn;
		return 0;
	} 
	if(m==n)
	{
		cout<<al;
		return 0;
	}
	return 0;
}
