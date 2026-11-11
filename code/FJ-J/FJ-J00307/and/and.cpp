#include<iostream>
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;
long long a[200005];
long long maxans=0;
int n,m;

void dfs(int yixuan,int pos,long long ans)
{
	if(pos>n)
	{
		return;
	}
	if(yixuan==m)
	{
		maxans=max(ans,maxans);
	}
	else{
		if(ans<=maxans)
		{
			return;
		}
		if(yixuan==0)
		{
			dfs(yixuan+1,pos+1,a[pos]);
			dfs(yixuan,pos+1,ans);
		}
		else{
			dfs(yixuan+1,pos+1,ans & a[pos]);
			dfs(yixuan,pos+1,ans);
		}
		
	}
}
bool ch(long long x)
{
	x=x+1;
	while(x>0)
	{
		if(x%2==1 && x!=1)
		{
			return false;
		}
		x=x/2;
	}
	return true;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxn=0;
	int flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(flag==1)
		{
			if(ch(a[i])==false)
			{
				flag=0;
			}
		}
	}

	
	if(m==1)
	{
		cout<<maxn;
	}
	else if(flag==1)
	{
		sort(a+1,a+n+1,greater<int>());
		maxans=a[1];
		for(int i=2;i<=m;i++)
		{
			maxans = maxans & a[i];
		}
	}
	else if(m==n)
	{
		maxans=a[1];
		for(int i=2;i<=m;i++)
		{
			maxans = maxans & a[i];
		}
	}
	
	else{
		dfs(0,1,0);
	}
	cout<<maxans;
	return 0;
}
