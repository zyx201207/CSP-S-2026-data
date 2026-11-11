#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i <= n;i ++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mmax=-0x3f3f3f3f;
	if (m==2)
	{
		for (int i =1;i <= n;i ++)
		{
			for (int j = 1;j <= n;j ++)
			{
				if (i==j)
					continue;
				int x=a[i]&a[j];
				mmax=max(mmax,x);
			}
		}
		cout<<mmax<<endl;
	}else if (m==1)
		cout<<a[n];
	else if (m==3)
	{
		for (int i =1;i <= n;i ++)
		{
			for (int j = 1;j <= n;j ++)
			{
				for (int k= 1;k <= n;k ++)
				{
					if (i==j||i==k||k==j)
						continue;
					int x=a[i]&a[j]&a[k];
					mmax=max(mmax,x);
				}
			}
		}
		cout<<mmax<<endl;
	}else if (m==4)
	{
		for (int i =1;i <= n;i ++)
		{
			for (int j = 1;j <= n;j ++)
			{
				for (int k= 1;k <= n;k ++)
				{
					for (int l = 1;l <= n;l ++)
					{
						if (i==j||i==k||i==l||j==k||j==l||l==k)
							continue;
						int x=a[i]&a[j]&a[k]&a[l];
						mmax=max(mmax,x);	
					}
				}
			}
		}
		cout<<mmax<<endl;
	}
	return 0;
}

