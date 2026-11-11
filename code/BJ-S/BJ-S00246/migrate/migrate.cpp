#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],ans=0,cur=INT_MAX;
void check(int x,int y,int now,int step)
{
	if(step>cur || now>y) 
	{
		return;
	}
	if(now==y)
	{
		if(step<cur)
		{
			cur=step;
			ans=1;
		}
		else if(step==cur)
		{
			ans++;
		}
		return;
	}
	for(int i=now+1;i<=y;i++)
	{
		if(a[i]<=a[now]+m)
		{
			check(x,y,i,step+1);
		}
		else break;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t; cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				ans=0,cur=INT_MAX;
				check(i,j,i,0);
				//cout<<i<<" "<<j<<" "<<ans<<endl;
				if(ans==2)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
