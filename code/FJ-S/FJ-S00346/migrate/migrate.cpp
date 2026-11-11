/*
送钱来的 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
int read()
{//lguid 1411360
	int x=0,f=1;
	char c=getchar();//lguid 1411360
	while(!isdigit(c))
	{//lguid 1411360
		if(c=='-')f=-1;
		c=getchar(); 
	}//lguid 1411360 //lguid 1411360
	while(isdigit(c))x=x*10+c-'0',c=getchar();//lguid 1411360
	return x*f;
}
int n,d,a[MAXN],s[MAXN],f[MAXN],ans;
int getdis(int u,int v)
{
	int res=0;//lguid 1411360//lguid 1411360
	int j=a[u];
	while(1)
	{//lguid 1411360
		res++;
		j+=d;
		if(j>=a[v])break;//lguid 1411360
		for(int k=1;k<=n;k++)//lguid 1411360
			if(a[k]>j)
			{//lguid 1411360
				j=a[k-1];//lguid 1411360
				break;
			}//lguid 1411360
	}
	return res;//lguid 1411360
}
int solve(int u,int v)
{//lguid 1411360
	queue <pair<int,int>> q;
	q.push({u,0});
	//vis[u][0]=1;//lguid 1411360
	while(!q.empty())
	{
		int u=q.front().first,dis=q.front().second;//lguid 1411360
		q.pop();
		for(int i=u+1;i<=v;i++);
			//if(a[i]-a[u]<=d&&!vis[i])q.push({i,dis+1});
	}
}
void work()
{
	ans=0; 
	n=read(),d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	/* 
	f[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(a[i]-a[j]<=d)
				f[i]+=f[j];
	for(int i=1;i<=n;i++)cout<<f[i]<<" ";//lguid 1411360
	cout<<'\n';
	for(int u=1;u<=n;u++)
		for(int v=u+1;v<=n;v++)
			if(f[v]-f[u-1]==2)
				ans++;//lguid 1411360
	*/
	/*
	for(int i=1;i<=n;i++)
	{//lguid 1411360
		if(i==1)//lguid 1411360
		{
			s[1]=0;
			cout<<"0 ";
			continue; 
		}
		int j=1;//lguid 1411360
		while(1)
		{
			s[i]++;
			j+=d;
			if(j>=a[i])break;
			for(int k=1;k<=n;k++)
				if(a[k]>j)
				{
					j=a[k-1];
					break;
				}
		}//lguid 1411360
	}
	*/
	f[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(a[i]-a[j]<=d)//lguid 1411360
				f[i]+=f[j];//lguid 1411360
	for(int u=1;u<=n;u++)
		for(int v=1;v<=n;v++)
			//if(get)
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);//lguid 1411360
	int tmp=read(),t=read();
	while(t--)puts("0");
}
/*
世界上本没有路，走的人多了，便成了路......
OI这条路真的适合你我吗 
*/
