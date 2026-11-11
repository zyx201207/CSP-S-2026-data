#include<bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i=l;i<=r;i++)
int n,m,now,a[500005],card[500005],rem[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	fr(i,1,n)scanf("%d",&a[i]);
	fr(N,1,n)
	{
		memset(rem,0,sizeof(rem));
		memset(card,0,sizeof(card));
		now=0;
		fr(k,N,n)
		{
			if(rem[a[k]])
			{
				fr(i,rem[a[k]]+1,now)
				{
					if(rem[card[i]]==i)rem[card[i]]=0;
					card[i]=0;
				}
				now=rem[a[k]];
			}
			else card[++now]=a[k],rem[a[k]]=now;
		}
		fr(i,1,m)
		{
			if(rem[i])ans[i]++;
		}
	}
	fr(i,1,m)printf("%d ",ans[i]);
	return 0;
}

