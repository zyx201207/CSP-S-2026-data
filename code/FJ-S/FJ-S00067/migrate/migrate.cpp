#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long int n,d,nd[1000],l[1000][1000];
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>nd[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				l[i][j]=nd[j]-nd[i];
		long long int sl=100,cnt=0;
		for(int i=1;i<=n;i++)
		{
			long long int cl=0,now=i;
			if(l[i][now]>d)continue;
			cl+=l[1][i];
			for(int j=i;j<=n;j++)
			{
				now=j;
				for(int m=now+1;m<=n;m++)
				{
					if(l[now][m]>d)continue;
					cl+=l[now][m];
					now=m;
				}
				if(now==n)sl=min(cl,sl);
			}
		}
		for(int i=1;i<=n;i++)
		{
			int cl=0,now=i;
			if(l[i][now]>d)continue;
			cl+=l[1][i];
			for(int j=i;j<=n;j++)
			{
				now=j;
				for(int m=now+1;m<=n;m++)
				{
					if(l[now][m]>d)continue;
					cl+=l[now][m];
					now=m;
				}
				if(cl==sl)cnt++;
			}
		}cout<<cnt;
	}
	
}
