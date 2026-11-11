#include<bits/stdc++.h>
using namespace std;

long long c[7000000];
long long q[7000000];
long long s[7000000];
long long n,m,ans;
long long f()
{
	int anst=-9999;
	int sumt=1;
	for(int i=1;i<=n;i++)
		q[i]=c[i];
	sort(q+1,q+n+1);
	for(int i=2;i<=n;i++)
	{
		if(c[i]==c[i-1])
			sumt++;
		else
		{
			anst=max(anst,sumt);
			sumt=1;
		}
	}
	return anst;
}
void dfs(int x,int s)
{
	if(m==x)
	{
		ans=max(ans,f());
		return;
	}
	for(int i=s;i<=n;i++)
	{
		c[i]++;
		dfs(x+1,s);
		c[i]--; 
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	if(n<=5000)
	{
		dfs(0,1);
		cout<<ans;
	}
	else
	{
		long long k=c[2]-c[1];
		for(int i=1;i<=n;i++)
		{
			s[i]=s[i-1]+i*k;
			if(s[i]>m)
			{
				cout<<i;
				break;
			}
		}
			
	}
		
} 
