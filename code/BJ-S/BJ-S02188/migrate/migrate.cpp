#include<bits/stdc++.h>
using namespace std;
long long x[2000001];
int f[2000001], f2[2000001];
long long n, d;
int c, t;
int main2()
{
	cin>>n>>d;
	for (int j=1;j<=n;j++)
	{
		cin>>x[j];
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=0;
		f2[i]=1;
		for (int j=i+1;j<=n;j++)
		{
			f[j]=1e9;
			for (int k=i;k<=j-1;k++)
			{
				if (x[j]-x[k]<=d)
				{
					if (f[k]+1<f[j])
					{
						f[j]=f[k]+1;
						f2[j]=f2[k];
					}
					else if (f[k]+1==f[j])
					{
						f2[j]+=f2[k];
					}
				}
			}
			if (f2[j]==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		main2();
	}
	return 0;
}
