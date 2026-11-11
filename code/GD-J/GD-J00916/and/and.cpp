#include <bits/stdc++.h>

using namespace std;
long long n,m,a[200005],maxx=LLONG_MIN;
void dfs(long long step,long long sum,long long chosen)
{
	if(step>n){if(chosen==m){maxx=max(maxx,sum);}return ;}
	if(chosen<m)
	{
		if(chosen==0){dfs(step+1,a[step],chosen+1);}
		else {dfs(step+1,sum&a[step],chosen+1);}
	}
	dfs(step+1,sum,chosen);
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
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		long long p=a[1];
		for(int i=2;i<=n;i++)
		{
			p=p&a[i];
		}
		cout<<p;
		return 0;
	}
	if(maxx<4)
	{
		long long za=0,oa=0,ta=0,tha=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0){za++;}
			if(a[i]==1){oa++;}
			if(a[i]==2){ta++;}
			if(a[i]==3){tha++;}
		}
		if(m<=tha){cout<<3;}
		else if(m<=tha+ta){cout<<2;}
		else if(m<=tha+ta+oa){cout<<1;}
		else {cout<<0;}
		return 0;
	}
	dfs(1,0,0);
	cout<<maxx;
	return 0;
}

