#include<bits/stdc++.h>
using namespace std;
long long a[2000010],f[2000010],dst[2000010];
long long rd[2000010];
queue<int> q;
long long C,T,n,d,ans,u;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>C>>T;
	for(int i=1;i<=2000010;i++)
	{
		dst[i]=LLONG_MAX;
		rd[i]=0;
		f[i]=0;
	}
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int j=1;j<=n;j++)
		{
			dst[j]=0;
			f[j]=1ll;
			q.push(j);
			while(!q.empty())
			{
				u=q.front();
				q.pop();
				for(int i=u+1ll;i<=n;i++)
				{
					if(a[i]-a[u]<=d)
					{
						if(dst[i]==dst[u]+1ll)
						{
							rd[i]++;
						}
						else if(dst[i]>dst[u]+1ll)
						{
							rd[i]=1ll;
							dst[i]=dst[u]+1ll;
						}
					}
					if(!f[i])
					{
						q.push(i);
						f[i]=1ll;
					}
				}
			}
			for(int i=j;i<=n;i++)
			{
				if(rd[i]==1ll*2)
				{
					ans++;
				}
			}
			for(int i=j;i<=n;i++)
			{
				dst[i]=LLONG_MAX;
				rd[i]=0;
				f[i]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

