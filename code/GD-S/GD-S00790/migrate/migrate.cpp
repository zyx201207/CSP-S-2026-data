#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=5005;
int c,t,n,d,ppp,x[N],ycl[M][M];
void dfs(int ks,int y,int bs,int kk)
{
	if(bs>kk) return;
	if(ks==y)
	{
		ppp++;
		return;
	}
	for(int i=ks+1;i<=y;i++) if(x[i]-x[ks]<=d) dfs(i,y,bs+1,kk);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c<=2)
		{
			int ans=0;
			for(int i=1;i<=5000;i++) for(int j=i+1;j<=5000;j++) ycl[i][j]=2e18+1;
			for(int i=1;i<=n;i++)
			{
				int now=x[i]+d,cnt=1;
				for(int j=i+1;j<=n;j++)
				{
					if(x[j]<=now) ycl[i][j]=cnt;
					else
					{
						now=x[j-1]+d,cnt++;
						if(x[j]<=now) ycl[i][j]=cnt;
						else break;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(ycl[i][j]>2e18) continue;
					ppp=0;
					dfs(i,j,0,ycl[i][j]);
					if(ppp==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
		else if(c==11||c==12)
		{
			int cj=x[2]-x[1];
			int gs=d/cj;
			int hh=2*gs-1;
			if(gs==0||gs==1) cout<<"0\n";
			else cout<<max(n-hh,0ll)<<"\n";
		}
		else
		{
			int hhh=0,jl=0;
			for(int i=1;i<=n;i++)
			{
				if(max(x[i]-x[1],x[n]-x[i])<=d)
				{
					jl=i;
					break;
				}
			}
			if(!jl) jl=n/2;
			for(int i=1;i<jl;i++)
			{
				int hh=x[i]+d;
				int l=i,r=n,da=0;
				while(l<=r)
				{
					int mid=(l+r)/2;
					if(x[mid]>hh)
					{
						da=mid;
						r=mid-1;
					}
					else l=mid+1;
				}
				int zs=0;
				if(!da) break;
				for(int j=jl-5;j<=jl+5;j++)
				{
					int tt=max(j,1ll);
					tt=min(j,n);
					if(j==i||j==da) continue;
					if(x[j]-x[i]<=d&&x[da]-x[j]<=d) zs++;
				}
				if(zs==2) hhh++;
			}
			cout<<hhh<<"\n";
		}
	}
	return 0;
}
