#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
const int MAXM=300010;
int n,m,a[MAXN];
bool b[MAXM];
int idx,head[MAXM],nxt[MAXM*2],v[MAXM*2];
long long ans[MAXM];
int read()
{
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return ans;
}
void add(int uu,int vv)
{
	idx++;
	nxt[idx]=head[uu];
	head[uu]=idx;
	v[idx]=vv;
}
void dfs(int uu,int fa)
{
	for(int i=head[uu];i!=0;i=nxt[i])
	{
		int vv=v[i];
		if(vv==fa) continue;
		dfs(vv,uu);
		ans[uu]+=ans[vv];
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		ans[a[i]]++;
	}
	for(int i=n;i>=1;i--)
	{
		if(b[a[i]]==0)
		{
			b[a[i]]=1;
			add(a[i],a[i+1]);
			add(a[i+1],a[i]);
		}
	}
	dfs(a[n],0);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
