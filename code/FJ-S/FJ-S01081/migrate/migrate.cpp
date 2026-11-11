#include <bits/stdc++.h>
using namespace std;
int a[10010];
int b[5010][510];
int tp[5010];
void df(int x,int y,int ans)
{
	if(x==y)
	{
		tp[ans]++;
		return ;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(b[x][i]==1)
		{
			df(i,y,ans+1);
		}
	}
}
bool ch(int x,int y,int n)
{
     df(x,y,0);
     int aaa=0;
     for(int i=1;i<=5050;i++)
     {
     	if(tp[i]>0)
     	{
     		aaa=tp[i];
		 }
     	
	 }
	 if(aaa==2)
	 {
	 	return 1;
	 }
	 return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					
					b[i][j]=1;
					b[j][i]=1;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				
				if(ch(i,j,n))
				{
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
