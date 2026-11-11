#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],s[N],sum,cnt,b[N],p[N],next,ans;
bool hs(long long a,long long b)
{
	return a>b;
}
void dfs(long long x)
{
	if(x==m)
	{
		for(int i=2;i<=m;i++)
		{
			p[i]=p[i-1]&p[i];
		}
		cnt=max(cnt,p[m]);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			p[x+1]=a[i];
			b[i]=1;
			dfs(x++);
			b[i]=0; 
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)
		{
			s[i]=s[i-1]&a[i];
		}
		ans=max(ans,a[i]);
	}
	if(m==1)
	{
		cout<<ans;
		return 0;
	}
	if(n==m) 
	{
		cout<<s[n];
		return 0;
	}
	if(n<=1000)
	{
		dfs(0);
		cout<<cnt;
	}
	else
	{
		sort(a+1,a+1+n,hs);
		for(int i=2;i<=m;i++)
		{
			a[i]=a[i-1]&a[i];
		}
		cout<<a[m];
	}
} 
