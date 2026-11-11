#include<bits/stdc++.h>
using namespace std;

long long w[500005];
long long l1[500005][25];
long long l2[500005][25];
long long t2[10000][10000];
long long N=9096944270305263617;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(long long i=1;i<=500;i++)
	{
		for(long long j=1;j<=20;j++)
		{
			l2[i][j]=N;
		}
	}
	for(long long i=1;i<=500;i++)
	{
		for(long long j=1;j<=500;j++)
		{
			t2[i][j]=N;
		}
	}
	for(long long i=1;i<=500;i++)
	{
			t2[i][i]=0;
	}
	
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;

	
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		long long a[k+1],t[k+1];
		for(long long j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(long long j=1;j<=k;j++)
		{
			for(long long j2=1;j2<=k;j2++)
			{
				bool qqq=0;
				for(long long j3=1;j3<=d&&(qqq==0);j3++)
				{
					if(l1[a[j]][j3]==a[j2])
					{
						l2[a[j]][j3]=min(l2[a[j]][j3],t[j]+t[j3]);
						qqq=1;
					}
					if(l1[a[j]][j3]==0)
					{
						l1[a[j]][j3]=a[j2];
						l2[a[j]][j3]=t[j]+t[j3];
						qqq=1;
					}
				}
				
			}
		}
	}
	
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<i;j++)
		{
			long long t3=N;
			for(long long j2=1;j2<=d;j2++)
			{
				if(l1[i][j2]!=0) t3=min(t3,l2[i][j2]+t2[l1[i][j2]][j]);
			}
			t2[i][j]=t3;
			t2[j][i]=t3;
		}
	}
	for(long long i=1;i<=q;i++)
	{
		long long x,y;
		cin>>x>>y;
		cout<<t2[x][y]+w[x]+w[y]<<"\n";
	}





} 


