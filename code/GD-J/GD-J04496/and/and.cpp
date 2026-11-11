#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct node{
	int x;
	string t;
}a[N];
int n,k,maxn,max_size,vis[N];
string solve_(int x)
{
	string u,v;
	while(x!=0)
	{
		u.push_back('0'+x%2);
		x=x>>1;
	}
	for(int i=u.size()-1;i>=0;i--)
	{
		v.push_back(u[i]);
	}
	return v;
}
string solve(int x)
{
	string u,v;
	while(x!=0)
	{
		u.push_back('0'+x%2);
		x=x>>1;
	}
	for(int i=1;i<=max_size-u.size();i++)
	{
		v.push_back('0');
	}
	for(int i=u.size()-1;i>=0;i--)
	{
		v.push_back(u[i]);
	}
	return v;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		maxn=max(maxn,a[i].x);
	}
	string cyz=solve_(maxn);
	max_size=cyz.size();
	for(int i=1;i<=n;i++)
	{
		a[i].t=solve(a[i].x);
	}
	int ans=0;
	for(int i=0;i<max_size;i++)
	{
		
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0)
			if(a[j].t[i]=='1')
			{
				sum++;
			}
		}
		if(sum>=k)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==0)
				if(a[j].t[i]=='0')
				{
					vis[j]=1;
				}
			}
			ans+=(1<<(max_size-i-1));
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

*/
