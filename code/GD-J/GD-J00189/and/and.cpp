#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],ans,m,b[15],c[200005],d[200005];
bool A=true,B=true,C=true;
void dfs(ll now,ll s,ll num)
{
	if(s==m)
	{
		ans=max(ans,num);
		return;
	}
	if(now>n) return;
	if(num<=ans) return;
	for(int i=now+1;i<=n;i++)
	{
		dfs(i,s+1,(num&a[i]));
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
	}
	else if(m==n-1)
	{
		b[1]=a[1],d[n]=a[n];
		for(int i=2;i<=n;i++)
		{
			b[i]=(b[i-1]&a[i]);
		}
		for(int i=n-1;i>=1;i--)
		{
			d[i]=(d[i+1]&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				ans=max(ans,d[i+1]);
			}
			else if(i==n) ans=max(ans,b[i-1]);
			else
			{
				ans=max(ans,(b[i-1]&d[i+1]));
			}
		}
	}
	else if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			dfs(i,1,a[i]);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ll tmp=a[i];
			while(tmp)
			{
				if(tmp%2==0) A=false;
				tmp/=2;
			}
			if(a[i]!=i-1) B=false;
			if(a[i]>4) C=false;
		}
		if(A)
		{
			sort(a+1,a+n+1);
			for(int i=1;i<=m;i++)
			{
				ans=(ans&a[i]);
			}
		}
		else if(B)
		{
			sort(a+1,a+n+1);
			for(int i=n;i>=n-m+1;i--)
			{
				ans=(ans&a[i]);
			}
		}
		else if(C)
		{
			for(int i=1;i<=n;i++) b[a[i]]++;
			for(int i=4;i>=1&&m;i--)
			{
				m-=b[i];
				ans=(ans&i);
			}
		}
		else
		{
			sort(a+1,a+n+1);
			for(int i=n;i>=n-m+1;i--)
			{
				ans=(ans&a[i]);
			}
		}
	}
	cout<<ans;
	return 0;
}
//写了1.9kb，优化一下多打几个部分分 
