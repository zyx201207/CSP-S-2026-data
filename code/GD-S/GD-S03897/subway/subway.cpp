#include<bits/stdc++.h>
using namespace std;
const int e=3e4+10,ee=510;
int c,n,m,d,q,w[e],wl[e][ee],wll[e][ee],a[ee][e],al[ee][e],t[ee][e],l[ee],rs,re;
struct st
{
	int tt,tp,ti;
};
void bfs()
{
	queue<st>q;
	int ans=INT_MAX;
	q.push({w[rs],0,rs});
	while(!q.empty())
	{
		st p=q.front();
		q.pop();
		if(p.tp==0)
		{
			if(p.ti==re)ans=min(ans,p.tt+w[re]);
			for(int i=1;wl[p.ti][i]!=0;i++)
			{
				if(wll[p.ti][i]==0)
				{
					wll[p.ti][i]=1;
					q.push({p.tt+t[wl[p.ti][i]][p.ti],1,wl[p.ti][i]});
				}
			}
		}
		else
		{
			for(int i=1;a[p.ti][i]!=0;i++)
			{
				if(al[p.ti][i]==0)
				{
					al[p.ti][i]=1;
					q.push({p.tt+t[p.ti][a[p.ti][i]],0,a[p.ti][i]});
				}
			}
		}
	}
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",l+i);
		for(int j=1;j<=l[i];j++)
		{
			scanf("%d%d",a[i]+j,t[i+1]+j);
			t[i][a[i][j]]=t[i+1][j];
			wl[a[i][j]][j]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&rs,&re);
		for(int i=0;i<e;i++)memset(wll[i],0,sizeof(wll[i]));
		for(int i=0;i<ee;i++)memset(al[i],0,sizeof(al[i]));
		bfs();
	}
	return 0;
}
