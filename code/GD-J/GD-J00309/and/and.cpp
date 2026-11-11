#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,yu=2147483647,mm,a[200005],t[50],ans,maxn,flag=1;
void dfs(int now,int x,int y)
{
	if(x+n-now+1<m)
	{
		return;
	}
	if(x==m)
	{
		ans=max(ans,y);
		return;
	}
	dfs(now+1,x,y);
	dfs(now+1,x+1,y&=a[now]);
}
bool check(int x)
{
	while(x)
	{
		if(x%2==0)
		{
			return 0;
		}
		x/=2;
	}
	return 1;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int xxx=a[i],ccc=1;
		while(xxx)
		{
			if(xxx%2==1)
			{
				t[ccc]++;
			}
			ccc++;
			xxx/=2;
		}
		mm=max(mm,ccc);
		if(!check(a[i]))
		{
			flag=0;
		}
		maxn=max(maxn,a[i]);
		yu&=a[i];
	}
	if(n<=20)
	{
		dfs(1,0,2147483647);
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		cout<<yu;
		return 0;
	}
	if(m==2)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			int s=2147483647;
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				s&=a[j];
			}
			maxn=max(maxn,s);
		}
		cout<<maxn;
		return 0;
	}
	if(flag==1)
	{
		sort(a+1,a+n+1,cmp);
		int xx=2147483647;
		for(int i=1;i<=m;i++)
		{
			xx&=a[i];
		}
		cout<<xx;
		return 0;
	}
	for(int i=mm;i>=1;i--)
	{
		if(t[i]>=m)
		{
			cout<<pow(2,i)-1;
			return 0;
		}
	}
	return 0;
}
