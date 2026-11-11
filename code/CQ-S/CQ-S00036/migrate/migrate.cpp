#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+8;
int C,T,n,d,ans,x[N],lp[N],rp[N],p[N],s[N],pre[N],nxt[N],pp[N],ss[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			p[i]=s[i]=1;
			pre[i]=nxt[i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			lp[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			if(lp[i]!=i)	p[lp[i]]++;
			rp[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
			if(rp[i]!=i)	s[rp[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(lp[i]!=i&&rp[lp[i]]==i)
			{
				nxt[i]=lp[i];
				pre[nxt[i]]=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			pp[i]=p[i];
			if(pre[i]!=-1)	pp[i]+=pp[pre[i]]-1;
		}
		for(int i=n;i>=1;i--)
		{
			ss[i]=s[i];
			if(nxt[i]!=-1)	ss[i]+=ss[nxt[i]]-1;
		}
		ans=0;
		for(int i=2;i<n-1;i++)
		{
			int ll=rp[i+1],lr=min(i-1,rp[i+2]-1);
			int rl=max(i+2,lp[i-1]+1),rr=lp[i];
			if(ll<=lr&&rl<=rr)
			{
				int ls=lr-ll+1,rs=rr-rl+1;
				if(lp[i+1]<=rr)	rs+=ss[rr]-1;
				if(rp[i]>=ll)	ls+=pp[ll]-1;
				ans+=ls*rs;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
