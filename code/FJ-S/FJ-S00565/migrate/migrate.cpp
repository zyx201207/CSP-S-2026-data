#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N];
int c,t,n,d;
int an=0,ans=0;
void dfs(int p,int x,int y)
{
	if(p==0&&x==y)
	{
		an++;
		return;
	}
	else if(x!=y&&p==0)
	return;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
		{
			dfs(p-1,i,y);
		}
		else
		break;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int r=i+j;
				int u=0;
				int p=0;
				for(int l=j;l<r;l++)
				{
					if(a[l+1]-a[l]>d)
					break;
					else
					u+=a[l+1]-a[l];
					if(u>d)
					u=a[l+1]-a[l],p++;
				}
				if(u)
				p++;
				dfs(p,j,r);
				if(an==2)
				ans++;
				an=0;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
