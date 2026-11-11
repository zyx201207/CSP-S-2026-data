#include<bits/stdc++.h>

using namespace std;
long long n,m;
long long  a[1000005];
int s;
int f(int x)
{
	int an=0;
	int c=m,k=x;
	while(c>0&&k>0)
	{
		if(c<(a[x]-a[k])) 
		{
			break;
		}
		c-=(a[x]-a[k]);
		
		k--;
		an++;
	}
	s=c;
	return an;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool s1=1,s2=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			s1=0;
		}
		if(i>=3)
		{
			if((a[2]-a[1])!=(a[3]-a[2]))
			{
				s2=0;
			}
		}
	}
	if(s1||s2)
	{
		cout<<f(n);
	}
	else
	{
		sort(a+1,a+n+1);
		int ans=0;
		int l=1,r=m;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,f(i));
		}
		cout<<ans;
	}
	return 0;
} 
