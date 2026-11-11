#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e6+10;
ll pos[maxn];
int go[maxn],back[maxn],chain[maxn],indeg[maxn];
void solve()
{
	int n;
	ll d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>pos[i];
	for(int i=1;i<=n;i++)
	{
		int fur=lower_bound(pos+i,pos+1+n,pos[i]+d)-pos;
		fur=min(fur,n);
		go[i]=fur;
		indeg[fur]++;
		back[fur]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==1 && go[i-1]==i) chain[i]=chain[i-1]+1;
	}
	ll ans=0;
	for(int r=1;r<=n;r++)
	{
		int pos=back[r]-chain[r]-1;
		if(indeg[pos]==2) 
		{
			int l=min(1,pos-chain[pos]);
			ans+=(pos-l+1);
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
}
