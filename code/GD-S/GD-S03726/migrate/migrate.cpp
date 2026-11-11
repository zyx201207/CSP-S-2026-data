#include<bits/stdc++.h>
using namespace std;
long long t,c,x[5005],ans,f[505][505][505],s[1005],d,n;
void dfs(int step,int m)
{
	if(step>m)
	{
		f[s[1]][s[m]][m]++;
		return ;
	}
	for(int i=s[step-1]+1;i<=n;i++)
	{
		if(x[i]-x[s[step-1]]<=d)
		{
			s[step]=i;
			dfs(step+1,m);
		}
		else return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=2;i<=n;i++) 
		{
			dfs(1,i);
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				for(int l=2;l<=n;l++)
				{
					
					if(f[i][j][l]==2)
					{
						ans++;
					}
					if(f[i][j][l])break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					f[i][j][k]=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
