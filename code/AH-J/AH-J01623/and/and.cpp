#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt,a[35],b[200005][35],c[35],ans,f[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a[1]=1;
	for(int i=2;i<=31;i++)
	{
		a[i]=a[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cnt=0;
		while(x)
		{
			b[i][++cnt]=x%2;
			if(x%2==1)
			{
				c[cnt]++;
			}
			x/=2;
		}
	}
	for(int i=31;i>=1;i--)
	{
		if(c[i]>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[j])
				{
					continue;
				}
				if(b[j][i]==0)
				{
					f[j]=1;
					for(int k=1;k<=31;k++)
					{
						if(b[j][k]==1)
						{
							c[k]--;
						}
					}
				}
			}
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}
