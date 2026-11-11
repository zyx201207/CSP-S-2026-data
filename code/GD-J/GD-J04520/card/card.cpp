#include<bits/stdc++.h>
struct node
{
	int num,st,ed;
};
node cs[5505];
int t[3005],n,m;
int st[5005],last[3005],r,vis[3005],ai[200005],top;
void slove(int x)
{
	memset(last,0,sizeof(last));
	memset(vis,0,sizeof(vis));
	r=0;
	for(int i=x;i<=n;i++)
	{
		if(last[cs[i].num]!=0)
		{
			for(int j=last[cs[i].num]+1;j<=r;j++)//O(N)
			{
				last[st[j]]=0;
			}
			r=last[cs[i].num];//eazy
		}
		else
		{
			r++;
			st[r]=cs[i].num;
			last[cs[i].num]=r;
		}
	}
	for(int i=1;i<=r;i++)
	{
	//	printf("%d ",st[i]);
		vis[st[i]]=1;
	}
	//printf("\n");
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ai[i]);
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			cs[i].num=ai[i];
		}
		for(int i=1;i<=n;i++)
		{
			slove(i);
			for(int i=1;i<=m;i++)
			{
				t[i]+=vis[i];
			}
		}
	}
	else
	{
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				t[ai[i]]++;
				if(ai[n]!=ai[i])
				{
					t[ai[n]]++;
				}
			}
		}
		else if(m<=3000)//12pts lisanhua
		{
			for(int i=1;i<=n;i++)
			{
				if(cs[top].num!=ai[i])
				{
					top++;
					cs[top].num=ai[i];
				}
				cs[top].st++;
			}
			n=top;
			for(int i=1;i<=top;i++)
			{
				slove(i);
				for(int j=1;j<=m;j++)
				{
					t[j]+=vis[j]*cs[i].st;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",t[i]);
	}
	return 0;
}
