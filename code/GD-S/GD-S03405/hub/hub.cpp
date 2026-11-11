#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k,a[2000009],b[2000009],L[2000009],R[2000009],to_[2000009],cnt[2000009],l,mid,r,mx,mi,s,f[2000009],vis[2000009],len,g[2000009],ans1,ans2;
void dfs(long long x,long long y)
{
	vis[x]=1;
	if(y>mx)
	{
		mx=y;
		mi=x;
	}
	for(int i=L[x];i<=R[x];++i)
	{
		if(vis[to_[i]]==0)
		{
			dfs(to_[i],y+1);
		}
	}
}
bool dfs2(long long x,long long y)
{
	vis[x]=1;
	if(x==y)
	{
		++len;
		g[len]=x;
		return true;
	}
	for(int i=L[x];i<=R[x];++i)
	{
		if(vis[to_[i]]==0)
		{
			if(dfs2(to_[i],y))
			{
				++len;
				g[len]=x;
				return true;
			}
		}
	}
	return false;
}
long long dfs3(long long x,long long w)
{
	vis[x]=1;
	long long y,z=0;
	for(int i=L[x];i<=R[x];++i)
	{
		if(vis[to_[i]]==0)
		{
			y=dfs3(to_[i],w)+1;
			if(y>z)z=y;
		}
	}
	if(z>=w)f[x]=1;
	return z;
}
bool check(long long x)
{
	if(x==0)return false;
	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
		f[i]=0;
		cnt[i]=0;
	}
	mx=0;
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
	}
	mx=0;
	s=mi;
	dfs(s,0);
	if(mx<=2*x)return true;
	len=0;
	ans1=0;
	ans2=0;
	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
	}
	dfs2(s,mi);
	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
	}
	for(int i=1;i<=len;++i)
	{
		vis[g[i]]=1;
	}
	for(int i=x+1;i<=len-x;++i)
	{
		f[g[i]]=1;
	}
	f[g[x+1]]=2;
	f[g[len-x]]=2;
	for(int i=x+2;i<len-x;++i)
	{
		for(int j=L[g[i]];j<=R[g[i]];++j)
		{
			if(vis[to_[j]]==0)
			{
				c=dfs3(to_[j],x)+1;
				if(c==x)f[g[i]]=2;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(f[i]>=1)++ans1;
	}
	for(int i=x+2;i<len-x;++i)
	{
		for(int j=L[g[i]];j<=R[g[i]];++j)
		{
			if(f[to_[j]])++cnt[i];
		}
	}
	mx=0;
	ans2=0;
	for(int i=x+2;i<len-x;++i)
	{
		if(f[g[i]]==1&&cnt[i]==2)
		{
			++mx;
		}
		else
		{
			mx=0;
		}
		if(mx>ans2)ans2=mx;
	}
	if(ans2>2*x)ans2=2*x;
	if(ans1-ans2<=k)return true;
	return false;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;++i)
		{
			R[i]=0;
			L[i]=0;
		}
		for(int i=1;i<n;++i)
		{
			scanf("%lld%lld",&a[i],&b[i]);
			++R[a[i]];
			++R[b[i]];
		}
		for(int i=1;i<=n;++i)
		{
			R[i]+=R[i-1];
			L[i]=R[i]+1;
		}
		for(int i=1;i<n;++i)
		{
			--L[a[i]];
			to_[L[a[i]]]=b[i];
			--L[b[i]];
			to_[L[b[i]]]=a[i];
		}
		if(k==n)
		{
			printf("0\n");
		}
		else
		{
			l=1;
			r=n;
			while(1)
			{
				mid=(l+r)/2;
				if(check(mid)==false)
				{
					l=mid+1;
				}
				else if(check(mid-1)==false)
				{
					printf("%lld\n",mid);
					break;
				}
				else
				{
					r=mid-1;
				}
			}
		}
	}
	return 0;
}
