#include<bits/stdc++.h>
using namespace std;
const int L=6e6+5;
int n,m,x,cnt,ans,son[L][2],siz[L];
void insert(int x)
{
	int u=0;
	for(int i=29;i>=0;i--)
	{
		int chr=0;
		if(x&(1<<i)) chr=1;
		if(!son[u][chr]) son[u][chr]=++cnt;
		u=son[u][chr],siz[u]++;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&x),insert(x);
	int u=0,base=(1<<29);
	for(;base;base/=2)
	{
		int v=son[u][1];
		if(siz[v]>=m) u=v,ans+=base;
		else m-=siz[son[v][1]],u=son[u][0];
	}
	printf("%d",ans);
	return 0;
}
