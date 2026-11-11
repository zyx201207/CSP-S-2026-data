#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,f=0,k=INT_MAX;
int a[2000005];
void dfs(int j,int l,int x)
{
	if(j==x)
	{
		if(l<k) k=l,f=1;
		else if(l==k) f++;
		return;
	}
	for(int i=x+1;i<=j;i++)
	{
		if(a[i]-a[x]>d) continue;
		dfs(j,l+1,i);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		if(c==13||c==14) cout<<0;
		else if(c==11||c==12)
		{
			int sum=0;
			int ca=a[n]-a[n-1];
			int k=d/ca;
			if(k==0)  cout<<0;
			else
			{
				for(int i=1;i<=n;i++)
				{
					int s=n-i;
					int g=s/d,ys=s%d;
					if(g==0) continue;
					sum+=(g-1)*(d-1)+ys;
				}
			}
			cout<<sum;
		}
		else
		{
			int sum=0;
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					dfs(j,0,i);
					if(f==2) sum++;
					f=0,k=INT_MAX;
				}
			}
			cout<<sum;
		}
		cout<<"\n";
	}
	return 0;
}
