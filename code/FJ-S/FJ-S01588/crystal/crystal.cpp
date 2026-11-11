#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int a[500010]; 
int b[500010];
int c[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=0;
	bool ff=0; 
	int p=a[1]-a[2];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) f=1;
		if(i>2)
		{
			if(a[i-1]-a[i]!=p) ff=1;
		}
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			else b[i]+=abs(a[i]-a[j]);
		}
	}
	if(f==0)
	{
		int w=0;
		int ans=0;
		int j=1;
		for(int i=n-1;i>=1;i--)
		{
			w+=j;
			if(w<=m)
			{
				ans++;
				j++;
			} 
		}
		cout<<ans;
	}
	else if(ff==0)
	{
		int w=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			w=w+p*i;
			if(w<=m)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	else
	{
		int k=1;
		int ant=b[1];
		for(int i=2;i<=n;i++)
		{
			if(b[i]<ant)
			{
				k=i;
				ant=b[i];
			}
		}
		for(int i=k+1;i<=n;i++)
		{
			c[i]=abs(a[i]-a[k]); 
		}
		for(int i=k-1;i>=1;i--)
		{
			c[i]=abs(a[i]-a[k]); 
		}
		sort(c+1,c+1+n);
		int sum=0;
		int z=0;
		for(int i=1;i<=n;i++)
		{
			sum+=c[i];
			if(sum<=m)	z++;
		}
		cout<<z;
	}
	return 0;
} 
