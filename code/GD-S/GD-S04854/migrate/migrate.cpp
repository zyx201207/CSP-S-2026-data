#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=5e3+5,inf=0x3f3f3f3f;
int c,t,n;
long long d,x[N],f[N];
//,gl[N],gr[N];
//f[i]:左边一次过来的区间
//g[i]     两次 
int G[M][M],GG[M][M];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	if(n<=1)
	{
		cout<<0<<'\n';
		return;
	}
	if(c>=11&&c<=12)
	{
		long long del=x[2]-x[1],t=d/del;
//		cout<<d<<' '<<del<<'\n';
		if(t<=1)
		{
			cout<<0<<'\n';
			return;
		}
		cout<<max(0ll,n-(2*t-1))<<'\n';
		return;
	}
//	if(c>=13&&c<=14)
//	{
//		int l=n,r=1;
//		for(int i=1;i<=n;i++)
//			if(x[i]-x[1]<=d&&x[n]-x[i]<=d)
//				l=min(l,i),r=max(r,i);
//		cout<<l<<' '<<r<<'\n';
//		if(r-l+1>=3)
//		{
//			cout<<0<<'\n';
//			return;
//		}
//		
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			G[j][i]=inf,GG[j][i]=0;
	for(int i=1,l=1;i<=n;i++)
	{
		while(x[i]-x[l]>d) l++;
		f[i]=l;
		for(int j=l;j<i;j++)
			G[j][i]=GG[j][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(j<f[i])
				G[j][i]=G[j][f[i]]+1;
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<i;j++)
//		{
//			cout<<j<<' '<<i<<' '<<GG[j][i]<<'\n';
//		}
//	cout<<'\n';
	for(int r=1;r<=n;r++)
		for(int l=1;l<f[r];l++)
			for(int k=f[r];k<r;k++)
				if(G[l][r]==G[l][k]+G[k][r])
					GG[l][r]+=GG[l][k]*GG[k][r];
				else break;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(GG[j][i]==2)
				ans++;
//			cout<<j<<' '<<i<<' '<<GG[j][i]<<'\n';
		}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}
/*
0 1
5 3
-3 0 2 3 4

*/

