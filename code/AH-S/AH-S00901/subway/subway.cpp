#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500005],k[505],b,a,q2,q,z,ee[500005][505],e[500005][25];
long long ans=0,ans1=LONG_LONG_MAX;
void eeee(long long a,long long q1)
{
	if(ee[a][q1]==0)
	return ;
	if(a==z)
	{
		ans+=ee[a][q1];
		ans1=min(ans1,ans);
		return;
	}
	for(int j=1;j<=e[a][0];j++)
		{
			long long kk=e[a][j];
			if(kk==q1)
			{
				eeee(a+1,kk);
			}
			if(kk!=q1)
			{
				long long kkk=ee[a][kk]+ee[a][q1];
				ans+=kkk;
				eeee(a+1,kk);
				ans-=kkk;
			}
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>b;
			ee[a][i]=b;
			++e[a][0];
			e[a][e[a][0]]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q2>>z;
		if(q2>z)
		{
			int t=q2;
			q2=z;
			z=t;
		}
		ans=0,ans1=LONG_LONG_MAX;
		ans+=w[q2]+w[z];
		for(int j=1;j<=e[q2][0];j++)
		{
			long long kk=e[q2][j];
			ans+=ee[q2][kk];
			eeee(q2+1,kk);
			ans-=ee[q2][kk];
		}
		cout<<ans1<<endl;
	}
}
