#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
inline int kd()
{
	char ca=getchar();
	bool fffff=true;
	int res=0;
	while(ca<'0'||ca>'9')
	{
		if(ca=='-') fffff=false;
		ca=getchar();
	}
	while(ca>='0'&&ca<='9') res=(res<<1)+(res<<3)+(ca^'0'),ca=getchar();
	return (fffff?res:-res);
}
int n,m;
int a[N],cnt[N],l[N],r[N],lst[N];
bool vis[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=kd(),m=kd();
	for(int i=1;i<=n;i++) a[i]=kd();
	for(int x=1;x<=n;x++)
	{
		memset(vis,0,sizeof(vis));
		memset(lst,0,sizeof(lst));
		for(int i=x+1;i<=n;i++) l[i]=i-1,r[i]=i+1;
		r[0]=x,l[x]=0,r[x]=x+1;
		for(int i=x;i<=n;i++)
		{
			if(lst[a[i]]&&l[r[lst[a[i]]]]==lst[a[i]])
			{
				l[i]=l[lst[a[i]]];
				r[l[lst[a[i]]]]=i;
			}
			lst[a[i]]=i;
		}
		for(int i=r[0];i<=n;i=r[i]) vis[a[i]]=1;
		for(int i=1;i<=m;i++) cnt[i]+=vis[i];
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}
