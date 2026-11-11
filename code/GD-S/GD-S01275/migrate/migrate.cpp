#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2000010,INF=1e18;
int c,tst,n,dis,px[M],l[M],r[M],s,d[M],f[M],q[M],ql,qr;
int bfs(int st,int pl,int pr)
{
//	pl=max(pl,st+1);
	pl=st;
	if(pl>pr)return 0;
	for(int i=pl;i<=pr;++i)d[i]=INF,f[i]=0;
	d[st]=0,f[st]=1;
	q[ql=qr=1]=st;
	for(int now=1,x;now<=qr;++now)
	{
		x=q[now];
		for(int j=r[x];j>x;--j)
			if(d[j]==INF)d[j]=d[x]+1,f[j]=f[x],q[++qr]=j;
			else if(d[j]==d[x]+1)f[j]=min(3ll,f[j]+f[x]);
			else break; 
//		for(int j=l[x];j<x;++j)
//			if(d[j]==INF)d[j]=d[x]+1,f[j]=f[st],q[++qr]=j;
//			else if(d[j]==d[x]+1)f[j]=min(3ll,f[j]+f[st]);
	}
	int s=0;
	for(int i=pl;i<=pr;++i)if(f[i]==2)++s;
	return s;
}
int calc(int pl,int pr)
{
	int s=0;
	for(int i=pl;i<pr;++i)s+=bfs(i,i+1,pr);
	return s;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>tst;
	while(tst--)
	{
		cin>>n>>dis,s=0;
		for(int i=1;i<=n;++i)cin>>px[i];
		for(int i=1,j=1;i<=n;++i)
		{
			while(j<n&&px[j+1]-px[i]<=dis)++j;
			r[i]=j;
		}
		for(int i=n,j=n;i;--i)
		{
			while(j>1&&px[i]-px[j-1]<=dis)--j;
			l[i]=j;
		}
		if(c==11||c==12)
		{
			bfs(1,1,n);
			for(int i=2;i<=n;++i)
				if(f[i]==2)s+=(n-i+1);
			cout<<s<<'\n'; 
			continue;
		}
		else if(c==13||c==14)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=2,l=1;i<=n+1;++i)
			if(i==n+1||px[i]-px[i-1]>dis)s+=calc(l,i-1),l=i;
		cout<<s<<'\n';
	}
	return 0;
}
