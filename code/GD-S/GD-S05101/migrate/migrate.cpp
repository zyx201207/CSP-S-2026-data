#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d,x[200020],zd,z,s;
void dfs(int u,int v,int l)
{
	if(u==v)
	{
		if(l<zd)
		{
			zd=l;
			s=1;
		}
		else if(l==zd)
		{
			s++;
		}
		return;
	}
	for(int i=u+1;i<=v;i++)
	{
		if(x[i]-x[u]>d)return;
		dfs(i,v,l+1);
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
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				zd=10e18;
				s=0;
				dfs(i,j,0);
				if(s==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
 } 
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/
