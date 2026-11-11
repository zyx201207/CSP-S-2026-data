#include<bits/stdc++.h>
using namespace std;
int a[200010],r[200010],f[200010];
int n,m,maxn;
void dfs(int pos,int step)
{
	if(step==m+1)
	{
		int ans=r[1];
		for(int i=2;i<step;i++) ans&=r[i];
		maxn=max(maxn,ans);
		return ;
	}
	for(int i=pos+1;i<=n;i++)
	{
		r[step]=a[i];
		dfs(i,step+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
    if(n<=20)
    {
		dfs(0,1);
		cout<<maxn;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) maxn=max(maxn,(a[i]&a[j]));
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		int t=a[1];
		for(int i=2;i<=n;i++) t&=a[i];
		cout<<t;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			int t;
			if(i==1) t=a[2];
			else t=a[1];
			for(int j=2;j<=n;j++)
			{
				if(i==j) continue;
				t&=a[j];
			}
			maxn=max(maxn,t);
		}
		cout<<maxn;
	}
}
