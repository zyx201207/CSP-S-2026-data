#include <bits/stdc++.h> 
using namespace std;
long long w[5005];
long long k[5005];
long long a[5005][5005];
long long t[5005][5005];
bool v[5005];//站 
bool vx[5005];//路 
long long ans=INT_MAX;
long long l,r,n,m,d,q;
void dfs(long long x,long long z,long long time)//路 站  时间 
{
	if(a[x][z]==r)
		ans=min(ans,time);
	if(!v[a[x][z-1]])
	{
		v[a[x][z-1]]=1;
		dfs(x,a[x][z-1],time+t[x][z-1]);
	}
	if(!v[a[x][z+1]])
	{
		v[a[x][z+1]]=1;
		dfs(x,a[x][z+1],time+t[x][z+1]);
	}
	for(long long i=1;i<=n;i++)
	{
		if(i==x) continue;
		for(long long j=1;j<=k[i];j++)
		{
			if(!vx[i]&&a[i][j]==a[x][z])
			{
				vx[i]=1;
				dfs(i,a[i][j],time+w[a[i][j]]+w[x]);
				vx[i]=0;
			}
		}
				
	}
}
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long fff;
	cin>>fff>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
		cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--)
	{
		long long x;
		cin>>l>>r;
		long long sum=INT_MAX;
		for(long long i=1;i<=n;i++)//x:局部最优路线选择 
			if(a[i][l])
				if(a[i][l]>sum)
					sum=min(sum,a[i][l]),x=i;
		dfs(x,l,t[x][l]);
		cout<<ans<<endl;
		ans=INT_MAX;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
