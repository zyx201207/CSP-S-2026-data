#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&~x) 
using namespace std;
const int N=2e6+10;
int x[N],f[N],g[N],sf[N],sg[N],sx[N],cf[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			sx[i]=sx[i-1]+x[i];
			f[i]=g[i]=0;
			sf[i]=sg[i]=0;
			cf[i]=0;
		}
		int pf=1,qf=0,pg=1,qg=0,l=0;
		x[l]=-INT_MAX;
		x[n+1]=x[n+2]=x[n+3]=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			while(x[i]-x[l]>d&&l<i)
			{
				l++;
			}
			if(l!=i)
			{
				while(x[l+2]-x[qf]>d&&qf<l)
				{
					qf++;
					sg[qf]=sg[qf-1]+g[qf];
					sf[qf]=sf[qf-1]+f[qf];
				}
				qf--;
				while(x[l+1]-x[pf]>d&&pf<l)
				{
					pf++;
				}
				while(x[l+1]-x[qg]>d&&qg<l)
				{
					qg++;
				}
				qg--;
				while(x[l]-x[pg]>d&&pg<l)
				{
					pg++;
				}
				g[i]=i-1-l+1+sg[qg]-sg[pg-1];
//				printf("l=%Ld, pf=%Ld, qf=%Ld, sg pf-1=%Ld, sg qf=%Ld\n",l,pf,qf,sg[pf-1],sg[qf]);
//				cout<<l<<' '<<i<<' '<<pf<<' '<<qf<<' '<<sg[pf-1]<<' '<<sg[qf]<<' ';
				f[i]=sf[i-1]-sf[l-1]+qf-pf+1+sg[qf]-sg[pf-1];
				cf[l]++;
				cf[i]--;
			}
//			cout<<f[i]<<'\n';
			ans+=f[i];
		}
		for(int i=1;i<=n;i++)
		{
			cf[i]+=cf[i-1];
			ans-=f[i]*cf[i];
//			cout<<cf[i]<<' ';
		}
		cout<<ans<<'\n';
	}
}
