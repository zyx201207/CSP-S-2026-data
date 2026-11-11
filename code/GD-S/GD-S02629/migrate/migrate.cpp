#include <bits/stdc++.h>
using namespace std;
int x[2000005],c[2000005],cc,t,n,d,use[2000005],now,ans,beans;
int check(int x,int y)
{
	int end=1,sum=0;
	while(x<y)
	{
		if (c[x]+sum<=d)
		{
			sum+=c[x];
		}else
		{
			end++;
			sum=0;
		}
		x++;
	}
	return end;
}
void dfs(int x,int y,int num,int mix)
{
	if (x==y)
	{
		if (num==mix)beans++;
		return ;
	}
	int sum=0;
	for (int i=x;i<y;i++)
	{
		if (c[i]+sum<=d){
			dfs(i,y,num+1,mix);
			sum+=c[i];
		}
		else 
		{
			break;
			
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>cc>>t;
	//先搞出两个岛的最小距离，然后枚举出每个可能的方法，再和最小距离比对，耶，暴力 
	while(t--)
	{
		ans=0;
		cin >>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin >>x[i];
		}
		for (int i=1;i<n;i++)
		{
			c[i]=x[i+1]-x[i];
		}
		for (int i=1;i<n;i++)//枚举起点和终点 
		{
			for (int j=i+1;j<=n;j++)
			{
				now=check(i,j);//最小距离
				dfs(i,j,0,now);
				if (beans==2)ans++; 
				
			}
		}
		cout <<ans<<endl;
	}
 } 
