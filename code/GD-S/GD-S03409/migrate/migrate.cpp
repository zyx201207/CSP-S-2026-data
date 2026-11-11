#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=2e18;
ll c,T,n,d,x[2000006],num1,num2,ans;
ll dp[5005][5005],f[5005][5005],g[5005];
ll U,V;
void dfs(ll u,ll y)
{
	if(u==V)
	{
		if(y<num1)
		{
			num1=y;num2=1;
		}
		else if(y==num1)
		{
			num2++;
		}
		return ;
	}
	for(int i=u+1;i<=V;i++)
	{
		if(x[i]-x[u]<=d) dfs(i,y+1);
		else break;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12)//A
		{
			if(d<=x[2]-x[1]) cout<<0<<endl;
			else cout<<max((ll)0,n-(d/(x[2]-x[1])*2-1))<<endl;
			continue;
		}
		if(c<=2)
		{
			ans=0;
			for(int i=1;i<=n;i++) 
				for(int j=i+1;j<=n;j++) 
				{
					num1=1e18,num2=0;
					U=i,V=j;
					dfs(U,0);
					if(num2==2)
					{
						ans++;
					}
				}
			cout<<ans<<endl;
			continue;
		}
		if(c<=10)
		{
			ans=0;
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=inf,f[i][j]=0,g[i]=0;
			for(int i=1;i<=n;i++) 
			{
				for(int j=i+1;j<=n;j++) 
				{
					if(x[j]-x[i]<=d) dp[i][j]=1,f[i][j]=1;
					else 
					{
						g[i]=j;break;
					}
				}
				if(g[i]==0) g[i]=n+1;
			}
			for(int i=1;i<=n;i++) dp[i][i]=0;
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					if(dp[i][k]>=inf) continue;
					for(int j=g[i];j<=n;j++) 
					{
						if(x[j]-x[i]<=d) {dp[i][j]=1;f[i][j]=1;continue;}
						ll num=dp[i][k]+dp[k][j];
						if(num<dp[i][j])
						{
							dp[i][j]=num;
							f[i][j]=f[i][k]*f[k][j];
						}
						else if(num==dp[i][j])
						{
							dp[i][j]=num;
							f[i][j]+=f[i][k]*f[k][j];
						}
					}
				}
			}
			for(int i=1;i<=n;i++) 
			{
				for(int j=i+1;j<=n;j++)
				{
					if(f[i][j]==2) 
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
/*
6 1
6 10
1 3 7 13 17 23
*/ 
