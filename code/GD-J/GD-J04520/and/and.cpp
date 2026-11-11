#include<bits/stdc++.h>
int n,m,ans;
int ai[200005];
int ycl[25];
int check1();
int check2();

void dfs1(int x);
int vis[25];

int qz[25],nqz[25];//第i位的0决断值

void dfs2(int x);
int cnt[15];

int tmp[1048580];
void tsort();

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ycl[1]=1;
	for(int i=2;i<=23;i++)
	{
		ycl[i]=ycl[i-1]*2;
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ai[i]);
	}
	if(n<=20)
	{
		dfs1(1);//25pts
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			for(int i=1;i<=n;i++)//5pts
			{
				ans=std::max(ans,ai[i]);
			}
		}
		else if(m==n)
		{
			ans=(~0)^(1<<31);//极大
			for(int i=1;i<=n;i++)//5pts
			{
				ans&=ai[i];
			}
		}
		else if(m==2)
		{
			for(int i=1;i<=n;i++)//15pts
			{
				for(int j=i;j<=n;j++)
				{
					if(i!=j)
					{
						ans=std::max(ans,ai[i]&ai[j]);
					}
				}
			}
		}
	}
	else
	{
		if(m==n-1)//10pts
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=21;j++)
				{
					if(ai[i]&ycl[j]==0)//该位为0
					{
						qz[j]++;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=21;j++)
				{
					nqz[j]=qz[j];
					if(ai[i]&ycl[j]==0)//该位为0
					{
						nqz[j]--;
					}
				}
				int res=0;
				for(int j=1;j<=21;j++)
				{
					if(nqz[j]==0)
					{
						res|=ycl[j];
					}
				}
				ans=std::max(ans,res);
			}
		}
		else if(check1())//10pts
		{
			for(int i=1;i<=n;i++)
			{
				cnt[ai[i]]++;
			}
			dfs2(0);
		}
		else if(check2())
		{
			tsort();
			ans=ai[m];
		}
	}
	printf("%d",ans); 
	return 0;
}
void dfs1(int x)
{
	if(x>n)
	{
		int cnt=0,res=(~0)^(1<<31);//极大
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				res&=ai[i];
				cnt++;
			}
		}
		if(cnt==m)
		{
			ans=std::max(ans,res);
		}
		return;
	}
	vis[x]=0;
	dfs1(x+1);
	vis[x]=1;
	dfs1(x+1);
	return;
}
int check1()
{
	for(int i=1;i<=n;i++)
	{
		if(ai[i]>4)
		{
			return 0;
		}
	}
	return 1;
}
void dfs2(int x)
{
	if(x>4)
	{
		int res=127,cnt1=0;
		for(int i=0;i<=4;i++)
		{
			if(vis[i]==1)
			{
				res&=i;
				cnt1+=cnt[i];
			}
		}
		if(cnt1>=m)
		{
			ans=std::max(ans,res);
		}
		return;
	}
	vis[x]=0;
	dfs1(x+1);
	vis[x]=1;
	dfs1(x+1);
	return;
}
int check2()
{
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=21;j++)
		{
			if(ycl[j]-1==ai[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			return 0;
		}
	}
	return 1;
}
void tsort()
{
	for(int i=1;i<=n;i++)
	{
		tmp[ai[i]]++;
	}
	int top=0;
	for(int i=1048576;i>=0;i--)//0!!!
	{
		for(int j=tmp[i];j>=1;j--)
		{
			top++;
			ai[top]=i;
		}
	}
	return;
}
