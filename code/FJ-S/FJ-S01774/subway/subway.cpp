#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,kdt[500010],ans[100010],tdt[501][490001],dl[510][25],p[510],k[510],x[510],y[510];
void dp(long long a,long long s,long long f)
{
	if(a==y[f]){ans[f]=min(ans[f],s);return;}
	if(s>=ans[f])return;
	for(long long i=1;i<=n;i++)
	{
		if(tdt[i][a]!=-1&&!p[i])
		{
			s+=tdt[i][a];
			for(long long j=1;j<=k[i];j++)
			if(dl[i][j]!=a)
			{p[i]=1;dp(dl[i][j],s+tdt[i][dl[i][j]],f);p[i]=0;}
		}
	}
}
int main()
{	
  	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(tdt,-1,sizeof(tdt));
	memset(ans,0x3f3f3f3f,sizeof(ans));
	cin>>c>>n>>m>>d>>q;long long a;
	for(long long i=1;i<=m;i++)
		cin>>kdt[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
		{
			cin>>a;cin>>tdt[i][a];
			dl[i][j]=a;
		}	
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		dp(x[i],kdt[x[i]]+kdt[y[i]],i);
	}
	for(long long i=1;i<=q;i++)
		cout<<ans[i]<<endl;
 	return 0;
}
