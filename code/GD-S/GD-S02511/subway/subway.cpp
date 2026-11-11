#include<bits/stdc++.h>
using namespace std;

const int N=200010;
int w[N];
struct node1
{
	int a1;
	int t1;	
};
struct node2
{
	int k1;
	node1 a[1000];	
}k[N];

struct node3
{
	int x;
	int y;
}pic[N];
int time_1[N];
int ret=1;
int c,n,m,d,q,num=1;
int dfs(int st,int d,int e,int t)
{
	if(st==e)
	{
		time_1[ret]=t;
		ret++;
	}
	if(d-1==1)return 0;
	if(true)
	{
		int nx=0;
		int nw=0;
		int tot=0;
		for(int i=1;i<=num;i++)
		{
			if(pic[i].y==st)
			{
				nw=pic[i].x;
				for(int xxxxxx=1;xxxxxx<=num;xxxxxx++)
				{
					if(pic[xxxxxx].y==nw)
					{
						nx=pic[xxxxxx].y;
						int fd=0;
						int flag=0;
						int now_xianlu1=0;
						for(int j=1;j<=n;j++)
						{
							for(int aaa=1;aaa<k[j].k1;aaa++)
							{
								if(k[j].a[aaa].a1==pic[i].y||k[j].a[aaa].a1==nx)
								{
									fd++;
									if(k[j].a[aaa].a1==pic[i].y)
									now_xianlu1=j;
								}
							}
							if(fd==2)
							{
								tot=0;
								flag=1;
								break;
							}
						}
						if(flag==0)
						{
							for(int kkk=1;kkk<=n;kkk++)
							{
								int fd1=0;
								int fd2=0;
								int now_xianlu=0;
								for(int aaa=1;aaa<k[kkk].k1;aaa++)
								{
									if(k[kkk].a[aaa].a1==pic[i].y)
									{
										fd1++;
										now_xianlu=aaa;
									}
									if(k[kkk].a[aaa].a1==nx)
									{
										fd2++;
										break;
									}
								}
								if(fd1==1&&fd2==0)
								{
									tot+=k[kkk].a[now_xianlu].t1;
									for(int www=1;www<=n;www++)
									{
										int fd11=0;
										int fd22=0;
										now_xianlu=0;
										for(int aaa=1;aaa<k[www].k1;aaa++)
										{
											if(k[www].a[aaa].a1==pic[i].y)
											{
												fd11++;
												break;
											}
											if(k[www].a[aaa].a1==nx)
											{
												fd22++;
												now_xianlu=aaa;
											}
										}
										if(fd11==0&&fd22==1)
										{
											tot+=k[www].a[now_xianlu].t1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		dfs(nw,d-1,e,t-tot);
	for(int i=1;i<=num;i++)
	{
		int nx=0;
		int nw=0;
		int tot=0;
		if(pic[i].x==st)
		{
			nw=pic[i].y;
			
			for(int xxxxxx=1;xxxxxx<=num;xxxxxx++)
			{
				if(pic[xxxxxx].x==nw)
				{
					nx=pic[xxxxxx].y;
					int fd=0;
					int flag=0;
					int now_xianlu1=0;
					for(int j=1;j<=n;j++)
					{
						for(int aaa=1;aaa<k[j].k1;aaa++)
						{
							if(k[j].a[aaa].a1==pic[i].x||k[j].a[aaa].a1==nx)
							{
								fd++;
								if(k[j].a[aaa].a1==pic[i].x)
								now_xianlu1=j;
							}
						}
						if(fd==2)
						{
							tot=0;
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						for(int kkk=1;kkk<=n;kkk++)
						{
							int fd1=0;
							int fd2=0;
							int now_xianlu=0;
							for(int aaa=1;aaa<k[kkk].k1;aaa++)
							{
								if(k[kkk].a[aaa].a1==pic[i].x)
								{
									fd1++;
									now_xianlu=aaa;
								}
								if(k[kkk].a[aaa].a1==nx)
								{
									fd2++;
									break;
								}
							}
							if(fd1==1&&fd2==0)
							{
								tot+=k[kkk].a[now_xianlu].t1;
								for(int www=1;www<=n;www++)
								{
									int fd11=0;
									int fd22=0;
									now_xianlu=0;
									for(int aaa=1;aaa<k[www].k1;aaa++)
									{
										if(k[www].a[aaa].a1==pic[i].x)
										{
											fd11++;
											break;
										}
										if(k[www].a[aaa].a1==nx)
										{
											fd22++;
											now_xianlu=aaa;
										}
									}
									if(fd11==0&&fd22==1)
									{
										tot+=k[www].a[now_xianlu].t1;
										break;
									}
								}
								
								if(d!=1)dfs(nw,d+1,e,t+tot);
								else dfs(nw,d+1,e,t+tot+k[now_xianlu1].a[st].t1);
							}
						}
					}
					else 
					{
						
						if(d!=1)dfs(nw,d+1,e,t);
						else
						{
							dfs(nw,d+1,e,t+k[now_xianlu1].a[st].t1);
						} 
					}
				}
				
			}
			
		}
	}
	if(d-1==1)return 0;
	if(true)
	{
		int nx=0;
		int nw=0;
		int tot=0;
		for(int i=1;i<=num;i++)
		{
			if(pic[i].y==st)
			{
				nw=pic[i].x;
				for(int xxxxxx=1;xxxxxx<=num;xxxxxx++)
				{
					if(pic[xxxxxx].y==nw)
					{
						nx=pic[xxxxxx].y;
						int fd=0;
						int flag=0;
						int now_xianlu1=0;
						for(int j=1;j<=n;j++)
						{
							for(int aaa=1;aaa<k[j].k1;aaa++)
							{
								if(k[j].a[aaa].a1==pic[i].y||k[j].a[aaa].a1==nx)
								{
									fd++;
									if(k[j].a[aaa].a1==pic[i].y)
									now_xianlu1=j;
								}
							}
							if(fd==2)
							{
								tot=0;
								flag=1;
								break;
							}
						}
						if(flag==0)
						{
							for(int kkk=1;kkk<=n;kkk++)
							{
								int fd1=0;
								int fd2=0;
								int now_xianlu=0;
								for(int aaa=1;aaa<k[kkk].k1;aaa++)
								{
									if(k[kkk].a[aaa].a1==pic[i].y)
									{
										fd1++;
										now_xianlu=aaa;
									}
									if(k[kkk].a[aaa].a1==nx)
									{
										fd2++;
										break;
									}
								}
								if(fd1==1&&fd2==0)
								{
									tot+=k[kkk].a[now_xianlu].t1;
									for(int www=1;www<=n;www++)
									{
										int fd11=0;
										int fd22=0;
										now_xianlu=0;
										for(int aaa=1;aaa<k[www].k1;aaa++)
										{
											if(k[www].a[aaa].a1==pic[i].y)
											{
												fd11++;
												break;
											}
											if(k[www].a[aaa].a1==nx)
											{
												fd22++;
												now_xianlu=aaa;
											}
										}
										if(fd11==0&&fd22==1)
										{
											tot+=k[www].a[now_xianlu].t1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		dfs(nw,d-1,e,t-tot);
	}
}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].k1;
		for(int j=1;j<=k[i].k1;j++)
		{
			cin>>k[i].a[j].a1>>k[i].a[j].t1;
		}
		for(int j=2;j<=k[i].k1;j++)
		{
			pic[num].x=k[i].a[j-1].a1;
			pic[num].y=k[i].a[j].a1;
			num++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,ed; 
		cin>>st>>ed;
		
		int fd=0;
		int time1=w[st];
		
		dfs(st,1,ed,time1);
		sort(time_1+1,time_1+ret+1);
		cout<<time_1[1]<<endl;
	}
	return 0;
 } 
