#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int a[200010];
bool st[200010];
int ans=0;
int n,m;

void dfs(int x,int y,int la)
{
	if(x==n+1|| y==m+1)
	{
		ans=max(ans,la);
		return;
	}
	
	
	
	dfs(x+1,y,la);
	
	if(y==0) la=a[x];
	dfs(x+1,y+1,la&a[x]);
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(m==1 &&n<=2000)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n &&n<=2000)
	{
		int d=a[1];
		for(int i=2;i<=n;i++)
		{
			d=d&a[i];
		}
		cout<<d;
		return 0;
	}
	if(m==2 && n<=2000)
	{
		int h=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				int u=a[i]&a[j];
				h=max(h,u);
			}
		}
		cout<<h;
		return 0;
	}

	dfs(1,0,0);
	cout<<ans;
}
