#include<bits/stdc++.h>
#define int long long
using namespace std;
int nex[5005],a[5005];
int f[5005],n,d;
void solve()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=n,j=n;i>=1;i--)
	{
		while(a[j]-a[i]>d) j--;
		nex[i]=j;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int ls=i,nw=i;
		memset(f,0,sizeof(f));
		f[i]=1;
		for(int j=i+1;j<=n;j++)
		{
			int ct=0;
			if(abs(a[nw]-a[j])<=d) ct+=f[nw];
			if(ls<nw-1&&abs(a[nw-1]-a[j])<=d) ct+=f[nw-1];
			if(ls<nw-2&&abs(a[nw-2]-a[j])<=d) ct+=f[nw-2];
			if(ct==2) ans++;
			f[j]=min(3ll,ct);
			if(nex[nw]==j) ls=nw,nw=j;
		}
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
}
