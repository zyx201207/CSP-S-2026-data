#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,d;
int a[2000010],dis[2000010],t[2000010];
void dfs(int s,int cnt)
{
	if(dis[s]>cnt)
	{
		dis[s]=cnt;
		t[s]=1;
	}
	else if(dis[s]==cnt)
	{
		t[s]++;
	}
	else
	{
		return ;
	}
	int temp=d;
	for(int i=s+1; i<=n; i++)
	{
		if(temp>=a[i]-a[i-1])
		{
			temp-=a[i]-a[i-1];
			dfs(i,cnt+1);
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,p;
	cin >> c >> p;
	while(p--)
	{
		cin >> n >> d;
		bool flag=true;
		for(int i=1; i<=n; i++)
		{
			cin >> a[i];
			if(i!=1 && i!=2)
			{
				if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				{
					flag=false;
				}
			}
		}
		if(flag)
		{
			d/=a[2]-a[1];
			if(d==0)
			{
				d++; 
			}
			if(d==1)
			{
				cout << 0 << endl;
				continue;
			}
			cout << n-d*2+1 << endl;
		}
		else
		{
			int cnt=0;
			for(int i=1; i<=n-1; i++)
			{
				memset(dis,0x3f,sizeof(dis));
				memset(t,0,sizeof(t));
				dfs(i,0);
				for(int j=i+1; j<=n; j++)
				{
					if(t[j]==2)
					{
						cnt++;
					}
				}
			}
			cout << cnt << endl;
		}
	}
	
	return 0;
}
