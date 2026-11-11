#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+10;
const ll inf=2e18;
int n;
ll d,f[N],x[N];
int cnt[N],ans;

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	ans=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
			f[i]=inf,cnt[i]=0;
		f[k]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
				if(x[i]-x[j]<=d)
				{
					if(f[j]+1<f[i]&&f[j]!=inf)
						f[i]=f[j]+1,cnt[i]=1;
					else if(f[j]+1==f[i])
						cnt[i]++;
				}
			if(cnt[i]==2&&i!=k)
				ans++;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T; cin>>c>>T;	
	while(T--) solve();
	return 0;
}

