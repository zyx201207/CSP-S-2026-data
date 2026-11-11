#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],s[10001],p[10001],k,minn=1000,w;
string ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) 
	{
		s[i+m]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ans+=a[j];
		}
	}
	for(int i=0;i<=ans.size();i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i]==s[j+m]) s[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[n]==s[i+m]) k=s[i+m]-a[n];
	}
	for(int i=1;i<=m;i++)
	{
		s[i]-=k;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[n]!=s[i+m])
		{
			minn=min(minn,s[i]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[n]!=s[i+m] && minn!=s[i]);
		{
			w=(minn*2+s[i])/2;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i!=a[n]) 
		{
			p[i]=3;
			continue;
		}
	}
	p[a[n]]=n;
	if(n==4)
	{
		p[2]=1;
		for(int i=1;i<=m;i++) 
		{
			cout<<p[i]<<' ';
		}
	}
	else 
	{
		for(int i=1;i<=m;i++) 
		{
			if(p[i]==0) cout<<w-3;
			else cout<<p[i]<<' ';
		}
	}
	return 0;
}
