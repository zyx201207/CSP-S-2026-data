#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,minn=1e9,cnt=0;
int sum=0;
int x[2000050];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dfs(int s,int e,int step)
{
	if(step>minn) return;
	if(s==e)
	{
		if(step<minn)
		{
			minn=step;
			cnt=0;
		}
		if(step==minn) cnt++;
	}
	for(int i=s+1;i<=n;i++)
	{
		if(x[i]-x[s]>d) break;
		dfs(i,e,step+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		sum=0;
		memset(x,0,sizeof(x));
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			x[i]=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				minn=1e9;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2)
				{
					sum++;
//					cout<<i<<' '<<j<<endl;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
