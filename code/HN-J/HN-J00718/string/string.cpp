#include<bits/stdc++.h>
using namespace std;

int n;
struct nd{
	int a;
	char c;
}g[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	long long w=0,js=0;
	for(int i=1;i<=n;i++)
	{
		cin>>g[i].a>>g[i].c;
		if(g[i].a==1) js++;
		w+=g[i].a;
	}
	if(n==1) 
	{
		cout<<0;
		return 0;
	}
	if(w<=10000)
	{
		string s;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=g[i].a;j++)
			{
				s+=g[i].c;
			}
		}
		long long m=s.size()/2-1,ans=0;
		for(int i=0;i<=m;i++)	if(s[i]!=s[s.size()-i-1]) ans++;
		cout<<ans;
		return 0;
	}
	if(js==n)
	{
		js=js/2;
		int ans=0;
		for(int i=1;i<=n;i++)	if(g[i].c!=g[n-i+1].c) ans++;
		cout<<ans;
		return 0;
	} 
	int i=1,j=n;
	long long ans=0,bz=0;
	while(1<2)
	{
		if(i>j) break;
		if(g[i].a<g[j].a)
		{
			bz=g[j].a-g[i].a;
			if(g[i+1].c!=g[j].c)
			{
				g[i+1].a-=bz;
				ans+=bz;
			}
			else	g[i+1].a-=bz;
			if(g[i].c!=g[j].c)	ans+=g[i].a;
		}	
		else if(g[i].a>g[j].a)
		{
			bz=g[i].a-g[j].a;
			if(g[i].c!=g[j-1].c)
			{
				g[j-1].a-=bz;
				ans+=bz;
			}
			else	g[j-1].a-=bz;
			if(g[i].c!=g[j].c)	ans+=g[j].a;
		}	
		else if(g[i].a==g[j].a)
		{
			if(g[i].c!=g[j].c)	ans+=g[i].a;
		}
		i++,j--;
	}
	cout<<ans;
	return 0;
}
