#include<bits/stdc++.h>
using namespace std;
long long dis[5001][5001];
long long su[5001][5001];
long long a[2000001];
long long vv,n,d;
void dfs(long long x)
{
	for(long long i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]>d)
		{
			break;
		}
		if(dis[vv][i]>dis[vv][x]+1)
		{
			dis[vv][i]=dis[vv][x]+1;
			su[vv][i]=su[vv][x];
		}
		else
		if(dis[vv][i]==dis[vv][x]+1)
		{
			su[vv][i]+=su[vv][x];
		}
	}
	if(x<n)
	dfs(x+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
long long c,t,i,j,an;
cin>>c>>t;
while(t--)
{
cin>>n>>d;
an=0;
for(i=1;i<=n;i++)
{
	cin>>a[i];
}
for(i=1;i<=n;i++)
{
	for(j=i+1;j<=n;j++)
	{
		dis[i][j]=1e9;
		su[i][j]=1;
	}
}
for(i=1;i<=n;i++)
{
	su[i][i]=1;
	vv=i;
	dfs(i);
}
for(i=1;i<=n;i++)
{
	for(j=i+1;j<=n;j++)
	{
		if(su[i][j]==2)
		{
			an++;
		}
	}
}
cout<<an<<endl;
}
return 0;
}

