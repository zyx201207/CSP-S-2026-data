#include<bits/stdc++.h>
using namespace std;

int ux;

struct L
{
	bool t;
	int w;
}p[300006];

int n,m;
int a[500006];
int cp;
int ans[300006];

void why_delete(int x)
{
	for(int i=n;i>=x;i--)
	{
		p[i].t=0;
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ux=scanf("%d%d",&n,&m);
	if(ux!=2) return 1;
	for(int i=1;i<=n;i++)
	{
		ux=scanf("%d",&a[i]);
		if(ux!=1) return 2;
	}
	for(int i=1;i<n;i++)
	{
		for(cp=i;cp<=n;cp++)
		{
			if(p[a[cp]].t==1)
			{
				for(int j=p[a[cp]].w;j<cp;j++)
				{
					if(p[a[j]].t==1)
					{
						ans[a[j]]--;
					}
					p[a[j]].t=0;
					
				}
			}
			p[a[cp]].t=1;
			p[a[cp]].w=cp;
			ans[a[cp]]++;
		}
		why_delete(i);
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
