#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],ans,minn,cnt;
void dfs(int now,int k,int i,int j)
{
	if(k==j)
	{
		if(now-1==minn)
		{
			cnt++;
		}
		else if(now-1<minn)
		{
			minn=now-1;
			cnt=1;
		}
		return;
	}
	for(int h=k+1;h<=n;h++)
	{
		if(x[h]-x[k]<=d)
		{
			dfs(now+1,h,i,j);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==0)
		{
			int tmp=0;
			for(int i=2;i<=n;i++)
			{
				tmp+=(x[i]-x[i-1]);
				if(tmp>d)
				{
					tmp=i-2;
					break;
				}
			}
			for(int i=tmp+2;i<=n;i++)
			{
				if(tmp==0)
				{
					break;
				}
				if((i-1)/tmp*tmp==2)
				{
					ans+=(n-i+1);
				}
			}
			cout<<ans<<"\n"; 
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					minn=j-i+1;
					cnt=0;
					dfs(1,i,i,j);
					if(cnt==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
}
