#include<bits/stdc++.h>
using namespace std;
int c,t,n,mi,way,cnt;
long long d;
long long a[2000006];
void dfs(int now,int time,int fi)
{
	if(now>fi||time>mi) return;
	else if(now==fi)
	{
		if(time==mi) way++;
		else
		{
			way=1;
			mi=time;
		}
		return;
	}
	if(a[fi]-a[now]<=d)
	{
		dfs(fi,time+1,fi);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[now+i]-a[now]>d) return;
			dfs(now+i,time+1,fi);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cnt=0;
		memset(a,0,sizeof(a)); 
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				mi=2000006;
				way=0;
				dfs(i,0,j);
				if(way==2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
