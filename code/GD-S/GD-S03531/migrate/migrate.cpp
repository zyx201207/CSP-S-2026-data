#include<bits/stdc++.h>
using namespace std;
using i64=int64_t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	i64 d;
	cin>>c>>t;
	if (c<=2)
	{	
		while (t--)
		{
			int ans=0;
			cin>>n>>d;
			vector<i64> x(n+1);
			for (int i=1;i<=n;i++)
				cin>>x[i];
			for (int u=1;u<n;u++)
			{
				for (int v=u+1;v<=n;v++)
				{
					int dis=v-u-1,cnt=0,minn=dis;
					if (dis<d) continue;
					for (int s=1;s<(1<<dis);s++)
					{
						if ([&]()
						{
							int last=u;
							for (int p=s;p;p&=p-1)
							{
								int i=u+__builtin_ctz(p)+1;
								if (x[i]-x[last]>d) return false;
								last=i;
							}
							if (x[v]-x[last]<=d) return true;
							else return false;
						}()) 
						{
							int len=__builtin_popcount(s);
							if (len<minn)
							{
								minn=len;
								cnt=1;
							}
							else if (len==minn) cnt++;
						}
					}
					if (cnt==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	else if (c==11||c==12)
	{
		while (t--)
		{
			cin>>n>>d;
			vector<i64> x(n+1);
			for (int i=1;i<=n;i++)
				cin>>x[i];
			i64 k=x[2]-x[1],q=d/k;
			if (q==1||n-2*q+1<=0) cout<<0<<'\n';
			else cout<<n-2*q+1<<'\n';
		}
	}
}
