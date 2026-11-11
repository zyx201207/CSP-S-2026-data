#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans,s;
bool check(long long x)
{
	long long o=x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				o=a[i];
				o&=a[j];
				if(o==x)return true;
			}
		}
	}
	if(x)return true;
	return false;
}
bool f[200005];
long long dp[5005][5005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	s=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		s&=a[i];
	}
	if(m==n)
	{
		cout<<s;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=2000)
	{
		m--;
		for(int i=1;i<=n;i++)
		{
			long long p=i,o=0,nm=a[i],t;
			for(int k=1;k<=n;k++)
			{
				f[k]=1;
			}
			f[i]=0;
			for(int j=1;j<=m;j++)
			{
				long long zd=0,lu=0;
				for(int k=1;k<=n;k++)
				{
					if(f[k])
					{
						o=nm;
						o&=a[k];
					}
					if(zd<o)zd=o,lu=k;
				}
				nm=zd;
				f[lu]=0;
			}
			ans=max(ans,nm);
		}
		cout<<ans;
	}
	else
	{
	cout<<a[n-m];
	}
	return 0;
}
