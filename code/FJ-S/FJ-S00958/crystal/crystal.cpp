#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,yu=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long c=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]==a[i])
		{
			b[c]++;
		}
		else
		{
			c++;
		}
	}
	sort(b+1,b+1+c);
	long long i=1,j=2;
	while(m>=0 && j<=n)
	{
		if(a[1]==a[n])
		{
			cout<<n;
			return 0;
		}
		long long ja;
		ja=abs(a[i]-a[j]);
		if(ja*i>m)
		m-=ja*i;
		ans++;
		i++;
		j++;
	}
	
	if(b[c]+1<=ans)
	{
		cout<<ans;
	}
	
	if(b[c]+1>ans)
	{
		cout<<b[c]+1;
	}
	return 0;
}
