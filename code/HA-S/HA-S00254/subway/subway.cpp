#include<bits/stdc++.h>
using namespace std;
long long c=0,n=0,m=0,q=0,d=0,k=0,t=0;
long long w[500005];
long long road[205][500005];
long long mxn=0;
long long tl=0,tr=0;
long long first_r[205];
long long first[500005];
long long ans=1e18;
long long minr[205][205];
long long minroad[205][500005];
queue<long long> qe;
void dfs(long long i)
{
	while(!qe.empty()){
		long long tf=qe.front();
		for(long long l=1;l<=n;l++)
		{
			if(minr[i][l]==0)
			{
				minr[i][l]=minr[i][tf]+minr[tf][l];
			}
			else
			minr[i][l]=min((minr[i][tf]+minr[tf][l]),minr[i][l]);
			if(first_r[l]==0)
			{
				qe.push(l);
				first_r[l]=1;
			}
		}
	}
}
void bfs(long long i)
{
	while(!qe.empty())
	{
		int ft=qe.front();
		for(long long l=1;l<=mxn;l++)
		{
			if(road[ft][l]!=0)
			{
				if(minroad[i][l]==0)
				{
					minroad[i][l]=minr[i][ft]+road[ft][l];
				}
				else
				{
					minroad[i][l]=min(minroad[i][l],(minr[i][ft]+road[ft][l]));
				}
			}
			for(long long j=1;j<=n;j++)
			{
				if(first_r[j]==0&&road[j][l]!=0)
				{
					first_r[j]=1;
					qe.push(j);
				}
			}
		}
	}
}
void build()
{
	for(long long i=1;i<=n;i++)
	first_r[i]=0;
	for(long long i=1;i<=mxn;i++)
	first[i]=0;
	}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k;
		for(int l=1;l<=k;l++)
		{
			long long a=0,b=0;
			cin>>a>>b;
			mxn=max(mxn,a);
			road[l][a]=b;
		}
	}
	for(long long i=1;i<=mxn;i++)
	{
		for(long long l=1;l<=n;l++)
		{
			for(long long j=1;j<=n;j++)
			{
				if(road[l][i]!=0&&road[j][i]!=0)
				{
					if(minr[l][j]==0)
					minr[l][j]=road[l][i]+road[j][i];
					else
					minr[l][j]=min(minr[l][j],(road[l][i]+road[j][i]));
				}
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		build();
		qe.push(i);
		dfs(i);
	}
	for(long long i=1;i<=n;i++)
	{
		build();
		first_r[i]=1;
		qe.push(i);
		bfs(i);
	}
	for(long long i=1;i<=q;i++)
	{
		build();
		cin>>tl>>tr;
		for(long long l=1;l<=n;l++)
		{
			ans=min((minroad[l][tl]+road[l][tr]),ans);
		}
		cout<<(ans+w[tl]+w[tr])<<"\n";
		ans=1e18;
	}
	return 0;
}
