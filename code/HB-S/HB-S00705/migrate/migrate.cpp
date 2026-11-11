#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int c,t;
int n,d,cnt,ans[N+1],s;
int p[N+1];
void dfs(int x,int y,int r)
{
	if(x==y)
	{
		ans[cnt++]=r;
		return;
	}
	for(int i=x+1;i<=y;i++)
	{
		//cout<<p[i]-p[x]<<" ";
		if(d>=(p[i]-p[x]))
			dfs(i,y,r+p[i]-p[x]);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		s=0;
		for(int i=1;i<=n;i++)cin>>p[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				memset(ans,0,sizeof(ans));
				cnt=0;
				dfs(i,j,0);
				sort(ans,ans+cnt);
				//cout<<i<<"  "<<j<<"\n";
				//for(int k=0;k<=cnt;k++)
				//	cout<<ans[k]<<" ";
				//cout<<"\n";
				if(ans[1]==ans[2]&&ans[2]!=ans[3])
					s++;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
