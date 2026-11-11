#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))
const int N=2e6+10;
int a[N],b[N],d[N],f[N];
unsigned long long c[N];
int n,m;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int ci,T;
	cin>>ci>>T;
	for(int tt=1;tt<=T;tt++)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int x=a[2]-a[1],fg=1,ans=0;
		for(int i=1;i<n;i++)
			fg&=(a[i+1]-a[i]==x);
		if(fg)
		{
			if(m<2*x) cout<<0<<'\n';
			else cout<<max(0ll,n-3-(m/x-2)*2)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				d[j]=2e9,c[j]=f[j]=0;
			queue<int> q;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=m) 
					d[j]=c[j]=1,q.push(j);
				else break;
			}
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(int v=u+1;v<=n;v++)
				{
					if(a[v]-a[u]<=m)
					{
						if(d[v]>d[u]+1) d[v]=d[u]+1,c[v]=c[u],f[v]=f[u],q.push(v);
						else if(d[v]==d[u]+1) c[v]+=c[u],f[v]|=f[u]|(c[v]>2);
					}
					else break;
				}
			}
			int res=0;
			for(int j=i+1;j<=n;j++)
				if(c[j]==2&&!f[j])
				{
					res++;
					//~ cout<<i<<" "<<j<<endl;
				}
			ans+=res;
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}
