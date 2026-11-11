#include<bits/stdc++.h>
using namespace std;
long long csd,qt,n,d,a[2000010],f[2000010],cnt[2000010],ans;
bool dcsl=true;
queue<long long> q;
void solve()
{
	cin>>n>>d;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<0<<"\n";
		return;
	}
	dcsl=true;
	for(long long i=1;i<n;i++) if(a[i+1]-a[i]!=a[2]-a[1]) dcsl=false;
	if(dcsl)
	{
		long long dd=d/(a[2]-a[1]);
		if(dd>=2) cout<<max(n-2*dd+1,0ll)<<"\n";
		else cout<<0<<"\n";
		return;
	}
	ans=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++) f[j]=1000000000,cnt[j]=0;
		f[i]=0;
		cnt[i]=1;
		for(long long j=i+1;j<=n;j++)
		{
			for(long long l=j-1;l>=i && a[j]-a[l]<=d;l--) f[j]=min(f[j],f[l]+1);
			for(long long l=j-1;l>=i && a[j]-a[l]<=d;l--) if(f[j]==f[l]+1) cnt[j]+=cnt[l],cnt[j]=min(cnt[j],3ll);
		}
		for(long long j=i;j<=n;j++)
		{
			ans+=(cnt[j]==2);
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>csd>>qt;
	while(qt--) solve();
	return 0;
}
