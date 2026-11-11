#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
struct node
{
	int x,id;
}b[M];
bool cmp(node A,node B)
{
	return  A.x>B.x;
}
vector<int>G[M],G1[N];
int a[N],st[M],siz[N];
bool v[M];
void dfs(int x)
{
	siz[x]=1;
	for(int y:G1[x])
	{
		dfs(y);
		siz[x]+=siz[y];
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int nn=0;
	for(int i=n;i>=1;i--)
	{
		if(!v[a[i]])
		{
			st[a[i]]=i;
			nn++;
			b[nn].x=i;
			b[nn].id=a[i];
			v[a[i]]=1;
		}
		else
		{
			G[a[i]].push_back(i);
		}
	}
	sort(b+1,b+nn+1,cmp);
	for(int i=1;i<=nn;i++)
	{
		int x=b[i].x,k=b[i].id;
		if(x!=n)
		{
			G1[st[a[x+1]]].push_back(x);
		}
		for(int j:G[k])
		{
			G1[st[k]].push_back(j);
		}
	}
	dfs(n);
	for(int i=1;i<=m;i++)
	{
		printf("%d ",siz[st[i]]);
	}
	return 0;
}
