#include<bits/stdc++.h>
// at 17:55
#define N1 5005
#define N2 2000005
using namespace std;
typedef long long ll;

ll n,d;
ll a[N2],f[N1][N1],g[N1][N1],q[N1];

void init()
{
	for(int i=0;i<=n;i++)a[i]=q[i]=0;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=g[i][j]=0;
}

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int hea=1,tai=1;
		g[i][i]=0,f[i][i]=1;
		q[1]=i;
		for(int j=i+1;j<=n;j++)
		{
			while(hea<=tai&&a[j]-a[q[hea]]>d)
				hea++;
			f[i][j]=0;
			if(hea<=tai)
			{
				int k=hea;
				g[i][j]=g[i][q[hea]]+1;
				while(k<=tai&&g[i][q[k]]==g[i][q[hea]])
					f[i][j]+=f[i][q[hea]],k++;
			}
			else g[i][j]=1e18;
			while(hea<=tai&&g[i][q[tai]]>g[i][j])
				tai--;
			q[++tai]=j;
			if(f[i][j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}

void init2()
{
	for(int i=0;i<=n;i++)a[i]=0;
}

void solve2()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll k=a[2]-a[1];
	ll bl=d/k;
	if(bl<=1){cout<<0<<'\n';return;}
	bl+=bl-1;
	cout<<max(0ll,n-bl)<<'\n';
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	int t,typ;cin>>typ>>t;
	if(typ<=10)while(t--)init(),solve();
	else if(typ<=12&&typ>=11)while(t--)init2(),solve2();
	else while(t--)cout<<0<<'\n';
	return 0;
}