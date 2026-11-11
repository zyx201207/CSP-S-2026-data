#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int c,t,n,a[N],d,ans,ta,rt;
int dfs(int x,int y,int ff)
{
	if(x==y)
		return ff;
		int tans=1e9,gs=0;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)tans=min(dfs(i,y,ff+1),tans);
		else break;
	}
	return tans;
}
void dfs2(int x,int y,int ff)
{
	if(x==y)
	{
		if(ff==rt)ta++;
		return;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)dfs(i,y,ff+1);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12)
		{
			int dis=a[2]-a[1];
			int k=dis/d;
		}
		else
		{
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
				{
					ta=0,rt=dfs(i,j,0);dfs2(i,j,0),ans+=(ta==2);
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
