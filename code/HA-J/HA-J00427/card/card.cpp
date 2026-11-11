#include <bits/stdc++.h>
using namespace std;
int n,m,r=1;
int a[500005],st[500005],ans[300005];
bool in[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if(in[a[j]])
			{
				while(st[--r]!=a[j])in[st[r]]=false;
				++r;
			}
			else st[r++]=a[j],in[a[j]]=true;
		}
		while(r>1)
		{
			++ans[st[--r]];
			in[st[r]]=false;
		}
	}
	for(int i=1;i<=m;++i)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
