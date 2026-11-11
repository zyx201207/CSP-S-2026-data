#include <bits/stdc++.h>
using namespace std;
int a[500010];
struct node
{
	int id,b;
}s[300010];
int b[300010],c[300010];
bool cmp(node x,node y)
{
	return x.b<y.b;
}
int ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) s[i].id=i;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[a[i]].b=i,b[a[i]]=i,c[a[i]]++;
	sort(s+1,s+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		int x=b[s[i].id];
		ans[s[i].id]+=c[s[i].id];
		x++;
		if(x<=n) x=b[a[x]],c[a[x]]+=c[s[i].id];
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
