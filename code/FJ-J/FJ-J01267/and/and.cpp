#include<bits/stdc++.h>
using namespace std;

int m,n,a[500005],h,b[500005],ans=-0x3f3f3f3f;

void dfs(int nw,int s)
{
	if(nw==n+1)
	{
		if(s==m)
		{
			int t=(1<<31)-1;
			for(int i=1;i<=m;i++) t=t&b[i];
			ans=max(ans,t);
			return ;
		}
		return;
	}
	if(s<m) 
	{
		b[++h]=a[nw];
		dfs(nw+1,s+1);
		h--;
	}
	dfs(nw+1,s);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=100)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
