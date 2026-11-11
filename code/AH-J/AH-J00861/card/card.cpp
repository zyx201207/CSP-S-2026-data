#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int a[N];
struct Node {
	int id,jt;//yanse,jiaru_time
} stk[N];
int h=0;
int pre[N];
int ans[N];
int n,m;

void print()
{
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int l=1,r=n;l<r;l++,r--) swap(a[l],a[r]);
	for(int i=1;i<=n;i++)
	{
		if(pre[a[i]])
		{
			for(;h>=pre[a[i]];h--)
			{
				ans[stk[h].id]+=(i-stk[h].jt);
				pre[stk[h].id]=0;
			}
		}
		else
		{
			stk[++h]={a[i],i};
			pre[a[i]]=h;
		}
	}
	for(;h;h--)
	{
		ans[stk[h].id]+=(n+1-stk[h].jt);
	}
	print();
	
	return 0;
}
