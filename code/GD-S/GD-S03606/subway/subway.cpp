#include<bits/stdc++.h>
using namespace std;
long long C,N,M,D,Q;
long long W[500005];
long long K[505];
long long nowwhere;
//long long where[500005][2];
long long ql,qr;
//long long can[500005][2];
//long long aa[50005][105];
//long long ql,qr;
long long dis[500005];
long long idcnt;
long long id[5005][105];
long long val[5005][105];
long long c,h[49545],e[2033323][2];
int main()
{
	scanf("%lld",&C);
	scanf("%lld%lld%lld%lld",&N,&M,&D,&Q);
	for(int i=1;i<=M;i++)
	{
		scanf("%lld",&W[i]);
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&K[i]);
		long long lstX,lstY;
lstX=0;
lstY=0;
		for(int j=1;j<=K[i];j++)
		{
			nowwhere++;
			long long X,Y;
			scanf("%lld%lld",&X,&Y);
			id[X][i]=++idcnt;
			val[X][i]=Y;
			if(lstX!=0)
			{
				c++;
				e[c][0]=h[idcnt-1];
				e[c][1]=idcnt;
				h[idcnt-1]=idcnt;
			}
			lstX=X;
		}
		K[i]+=K[i-1];
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			
		}
	}
	for(int j=1;j<=idcnt;j++)
	{
		
	}
}
