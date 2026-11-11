#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int a[N];
int n,m;
int b[N],cnt=0;
bool vis[N];
long long Bfs(long long cnt,long long sum)
{
	if(cnt==m)
	{
		return sum;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
			    vis[i]=0;
			    return(cnt+1,sum&a[i]);
			    vis[i]=1;
		    }
		}
		 
	}
	return 0;
}
bool Cmp(const int &a,const int& b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=2000)
	{
		memset(vis,1,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long maxn=-1;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			maxn=max(Bfs(1,a[i]),maxn);
			vis[i]=1;
			cout<<maxn<<endl;
		}
		cout<<maxn;
	}
	else
	{
		if(n==m+1)
		{
			memset(vis,1,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		 
		sort(a+1,a+n+1,Cmp);
		long long maxn=a[1];
		for(int i=2;i<n;i++)
		{
			maxn=maxn&a[i];
		}
		cout<<maxn;
		}
		else
		cout<<0;
	}
	return 0;
}
