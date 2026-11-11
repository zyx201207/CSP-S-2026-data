#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q;
struct node
{
	long long to,time;
}t[5005];
long long a[5005],p[5005],ans[5005][5005],g[5005][5005];
void f()
{
	long long x,y,z;
	for(z=1;z<=m;z++)
	{
		for(x=1;x<=m;x++)
		{
			for(y=1;y<=m;y++)
			{ 
				ans[x][y]=min(ans[x][y],ans[x][z]+ans[z][y]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ans,0x3f,sizeof(ans));
	long long i,j,k,c;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>p[i];
		for(j=1;j<=p[i];j++)
		{
			cin>>t[j].to>>t[j].time;
		}
		for(j=1;j<=p[i]-1;j++)
		{
			for(k=j+1;k<=p[i];k++)
			{
				g[t[j].to][t[k].to]=t[j].time+t[k].time;
				g[t[k].to][t[j].to]=t[j].time+t[k].time;
				ans[t[j].to][t[k].to]=t[j].time+t[k].time;
				ans[t[k].to][t[j].to]=t[j].time+t[k].time;
			}
		}
	}
	f();
	for(i=1;i<=q;i++)
	{
		long long from,end;
		cin>>from>>end;
		cout<<ans[from][end]+a[from]+a[end]<<"\n";
	}
	exit(0);
}
