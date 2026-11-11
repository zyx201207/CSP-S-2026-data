#include<bits/stdc++.h>
using namespace std;
vector<int> a[1000005];
int b[1000005];
int c[1000005];
int f[1000005];
int find(int x)
{
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
int dep[1000005];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int y:a[x])
	{
		if(y!=fa)dfs(y,x); 
	}
	return;
}
bool check(int x,int n,int k)
{
	int l=1,r=0;
	for(int i=1;i<=n;i++)f[i]=0x3f3f3f3f;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].size()==1&&dep[i]>dep[cnt])cnt=i;
	}
	f[cnt]=0;
	c[++r]=cnt;
	int s=0;
	while(l<=r)
	{
		int b=c[l++];
		if(!s&&f[b]>=x)s=b;
		for(int d:a[b])
		{
			if(f[d]>f[b]+1)
			{
				f[d]=f[b]+1;
				c[++r]=d;
			}
		}
	}
	if(!s)return 1;
	l=1,r=0;
	for(int i=1;i<=n;i++)f[i]=0x3f3f3f3f;
	f[s]=0;
	c[++r]=s;
	int t=0;
	while(l<=r)
	{
		int b=c[l++];
		if(!t&&f[b]>x)t=b;
		for(int d:a[b])
		{
			if(f[d]>f[b]+1)
			{
				f[d]=f[b]+1;
				c[++r]=d;
			}
		}
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)if(f[i]>x)return 0;
		return 1; 
	}
	if(!t)return 1;
	l=1,r=0;
	for(int i=1;i<=n;i++)f[i]=0x3f3f3f3f;
	f[s]=f[t]=0;
	c[++r]=s;
	c[++r]=t; 
	while(l<=r)
	{
		int b=c[l++];
		for(int d:a[b])
		{
			if(f[d]>f[b]+1)
			{
				f[d]=f[b]+1;
				c[++r]=d;
			}
		}
	}
	for(int i=1;i<=n;i++)if(f[i]>x)return 0;
	return 1;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int sid,T,n,k,x,y;
	scanf("%d%d",&sid,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		if(sid<=3)
		{
			int ans=0x3f3f3f3f;
			for(int i=0;i<(1<<n);i++)
			{
				int cnt=0;
				for(int j=0;j<n;j++)
				{
					if((i>>j)&1)b[++cnt]=j+1,c[j+1]=1;
				}
				if(cnt!=k)continue;
				for(int j=1;j<=n;j++)f[j]=j;
				for(int j=1;j<=cnt;j++)
				{
					for(int k:a[b[j]])
					{
						if(!((i>>(k-1))&1))continue;
						f[find(k)]=find(b[j]);
					}
				}
				int cnt1=0,cnt2=0;
				for(int j=1;j<=cnt;j++)
				{
					x=find(b[j]);
					if(!cnt1)cnt1=x;
					else if(x!=cnt1)
					{
						if(!cnt2)cnt2=x;
						else if(x!=cnt2)cnt2=-1;
					}
				}
				if(cnt2==-1)continue;
				for(int j=1;j<=n;j++)f[j]=0x3f3f3f3f;
				int l=1,r=0;
				for(int j=1;j<=cnt;j++)f[b[j]]=0,c[++r]=b[j];
				while(l<=r)
				{
					int d=c[l++];
					for(int e:a[d])
					{
						if(f[e]>f[d]+1)
						{
							f[e]=f[d]+1;
							c[++r]=e;
						}
					}
				}
				ans=min(ans,f[c[n]]);
			}
			printf("%d\n",ans);
			continue;
		}
		dfs(1,0);
		if(k<=2)
		{
			int l=0,r=n,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(check(mid,n,k))r=mid;
				else l=mid+1;
			}
			printf("%d\n",l);
			continue;
		}
		printf("%d\n",n-k);
	}
}
