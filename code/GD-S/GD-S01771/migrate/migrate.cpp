#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int ans,d,sum;
void dfs(int a1,int b1)
{
	if(a1==b1)
	{
		ans++;
	}
	if(abs(a[b1]-a[a1])<=d)
	{
		for(int i=1;i<=abs(a[b1]-a[ai]);i++)
		{
			dfs(a1+i,b1);
		}
	}
} 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dfs(i,j);
				if(ans==2) 
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;ans=0;
	}
}
