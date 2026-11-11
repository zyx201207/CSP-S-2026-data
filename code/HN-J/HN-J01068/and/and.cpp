#include<bits/stdc++.h>
using namespace std;
int a[200005],ans,n,m,maxx=-1,he=0,f=1;
void dfs(int step,int dq,int an)
{
	if(step==m)
	{
		ans=max(ans,an);
		return;
	}
	if(dq==n+1||n-dq-2<m-step)
	{
		return;
	}
	if(an==0)
	{
		dfs(step+1,dq+1,a[dq]);
		dfs(step,dq+1,0);
	}
	else
	{
		dfs(step+1,dq+1,an&a[dq]);
		dfs(step,dq+1,an);
	}
}
bool k(int x)
{
	while(x)
	{
		if(x%2!=1)
		{
			return 0;
		}
		x/=2;
	}
	return 1;
}
bool cmp(int q,int d)
{
	return q>d;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(he==0)
		{
			he=a[i];
		}
		else
		{
			he&=a[i];
		}
		if(!k(a[i]))
		{
			f=0;
		}
	}
	if(m==1)
	{
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n)
	{
		cout<<he<<endl;
		return 0;
	}
	if(f==1)
	{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
