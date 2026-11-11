#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long maxv,n,m,a[maxn],c[maxn],s[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s));
		long long tmp=0;
		for(int j=1;j<=n;j++)
		{
			c[i]=a[i]-a[j];
			if(c[i]>=0)
			{
				s[++tmp]=c[i];
			}
		}
		sort(s+1,s+tmp+1);
		long long ans=0,x=m;
		for(int j=1;j<=tmp;j++)
		{
			if(s[j]<=x)
			{
				x-=s[j];
				ans++;
			}
		}
		maxv=max(maxv,ans);
	}
	cout<<maxv;
	return 0;
}
