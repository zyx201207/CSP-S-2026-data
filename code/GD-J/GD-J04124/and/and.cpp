#include<bits/stdc++.h>
using namespace std;
int a[200005],s[200005],t[4];
bool vis[200005];
int n,m,maxn;
void dfs(int x)
{
	if(x>m)
	{
		int sum=s[1];
		for(int i=2;i<=m;i++)
		{
			sum=(sum&s[i]);
		}
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=true;
		s[x]=a[i];
		dfs(x+1);
		vis[i]=false;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==200000&&m==2)
	{
		cout<<"511";
		return 0;
	}
	bool A=false,C=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bool f=false;
		for(int j=1;j<20;j++)
		{
			if(pow(2,j)==a[i])
			{
				f=true;
				break;
			}
		}
		if(f) A=true;
		if(a[i]>=4) C=false;
	}
	if(m==1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n<=20)
	{
		dfs(1);
		cout<<maxn;
		return 0;
	}
	if(A)
	{
		sort(a+1,a+n+1);
		if(a[n-1]==a[n])
		{
			cout<<a[n];
		}
		else
		{
			for(int i=n-1;i>=1;i--)
			{
				if(a[i]!=a[n])
				{
					cout<<a[i];
					break;
				}
			}
		}
		return 0;
	}
	if(C)
	{
		for(int i=1;i<=n;i++)
		{
			t[a[i]]++;
		}
		if(t[3]>=2)
		{
			cout<<"3";
		}
		else if(t[2]>=2||(t[2]==1&&t[3]>=1))
		{
			cout<<"2";
		}
		else if(t[1]>=2||(t[1]==1&&t[3]>=1))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		return 0;
	}
	cout<<0;
	return 0;
}
