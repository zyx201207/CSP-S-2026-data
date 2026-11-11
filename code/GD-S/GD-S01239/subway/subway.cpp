#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long t[100005],k[100005][505];//第i个站到第j条线的时间 
long long lz[505],cnt=0;
bool jl[100005][505];
long long pq[100005],zq[100005];//第i个规划的起点，第i个规划的终点 
long long miii(long long x,long long y,long long sum,long long mink)
{
	long long qiqi=x,kl=y,num=sum;
	long long f=10e5+1;
	bool jk=false;
	if(qiqi==kl)
	{
		num+=t[kl];
		if(num<mink)
		{
			mink=num;
		}
	}	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(jl[i][j]==false)
			{
				jk=true;
			}
		}
	}
	if(!jk)
	{
		return mink;
	}
	for(int i=1;i<=n;i++)
	{
		if(k[qiqi][i]<f)
		{
			for(int j=1;j<=m;j++)
			{
				if(k[j][i]<f&&j!=qiqi&&!jl[j][i])
				{
					num+=k[qiqi][i]+=k[j][i];
					jl[qiqi][i]=true;
					jl[j][i]=true;
					miii(j,kl,num,mink);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			k[i][j]=10e6;
			jl[i][j]=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>lz[i];
		for(int j=1;j<=lz[i];j++)
		{
			long long zh,sh;//站与时间 
			cin>>zh>>sh;
			k[zh][i]=sh; 
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long xq,xz;
		cin>>xq>>xz;
		pq[i]=xq;
		zq[i]=xz;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<miii(pq[i],zq[i],0,10e7)+t[pq[i]]<<endl;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				k[i][j]=10e6;
				jl[i][j]=false;
			}
		}
	}
	return 0;
}
