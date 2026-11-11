#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=5010;
ll c,t,n,d,a[N],ans;
ll mp[N][N],p[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		memset(mp,0x3f3f3f,sizeof(mp));
		memset(p,0,sizeof(p));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			mp[i][i]=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d) break;
				mp[i][j]=mp[j][i]=1;
				p[i][j]=p[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)	
				for(int j=1;j<=i;j++)
					if(i!=j&&i!=k&&j!=k&&abs(a[k]-a[i])<=d&&abs(a[k]-a[j])<=d)
					{
						ll u=mp[i][k]+mp[k][j];
						if(u==mp[i][j])
						{
							p[i][j]++;
							if(p[i][j]==2) 
							{
								ans++;
							}
							if(p[i][j]==3) ans--;
						}
						if(u<mp[i][j])
						{
							if(p[i][j]==2) ans--;
							p[i][j]=1;
							mp[i][j]=u;
						}
					}
		cout<<ans<<"\n";
	}
}
