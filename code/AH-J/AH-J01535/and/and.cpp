#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
int ans=0;
void dfs(int x,int y,int s)
{
	if(s==m)
	{
		ans=max(y,ans);
		return;
	}
	if(x>n)
		return;
	if(s==0)
		dfs(x+1,a[x],s+1);
	else
		dfs(x+1,a[x]&y,s+1);
	dfs(x+1,y,s);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int an6=0,an7;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		an6=max(an6,a[i]);
		if(i==1)
		{
			an7=a[1];
		}
		else
		{
			an7=an7&a[i];
		}
	}
	if(m==1)
	{
		cout<<an6;
		return 0;
	}
	if(m==n)
	{
		cout<<an7;
		return 0;
	}
	if(an6<4)
	{
		int p=0,q=0,r=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				p++;
			else if(a[i]==2)
				q++;
			else
				r++;
			if(r>=m)
			{
				cout<<3;
			}
			else if(p+r>=m)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
	}
	if(n<=2000)
	{
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
