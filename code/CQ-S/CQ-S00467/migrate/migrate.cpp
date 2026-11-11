#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,a[N],n,d,s;
void dfs(int mb,int u,int l)
{
	if(l==0&&u==mb) 
	{
		s++;
		return ;
	}
	for(int i=u+1;i<=mb;i++) 
	{
		if(a[u]+d>=a[i]) dfs(mb,i,l-1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=10)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i+1]-a[i]>d) break;
				for(int j=i+1;j<=n;j++)
				{
					int t;
					if((a[j]-a[i])%d==0) continue;
					t=(a[j]-a[i])/d+1;
					s=0;
					dfs(j,i,t);
					if(s==2) ans++;
				}
			}
			cout<<ans<<' ';
		}
	}
	return 0;
 }
//luogu:Super_qwq 
