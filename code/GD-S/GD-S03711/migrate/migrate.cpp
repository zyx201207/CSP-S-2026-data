#include<bits/stdc++.h>
using namespace std;
long long c,t,a[10005],n,d,f[10005][10005],s[10005];
long long dfs(long long begin,long long end,long long t,long long dir)
{
	int ans=0;
	if(f[begin][end]!=0)return f[begin][end];
	if(a[end]-a[begin]<d)return 1;
	if(t>dir)return 0;
	for(int i=begin;i<=begin+d;i++)
	{
		ans+=dfs(i,end,t+1,dir);
	}
	return f[begin][end]=ans;
	
}
int ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j+=d)
			{
				for(int k=j;k<j+d;k++)
				{
					s[k]=(j-i)/d;
				}
			}
			s[i]=0;
			for(int j=0;j<n;j++)
			{
				if(dfs(i,j,0,s[j])==2)ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=0;i<n;i++)
		{
			a[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			s[i]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
