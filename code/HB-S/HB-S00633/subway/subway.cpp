#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005],a[500005],t[500005],x[500005],y[500005],ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=y[i];i++)
	{
		ans+=w[x[i]];
		ans+=w[y[i]];
		if(a[i]==x[i]||a[i]==y[i]) ans+=t[i];
		x[i]++;
		if(x[i]==y[i]) 
		{
			cout<<ans<<"\n";
			ans=0;
		}
	}
	return 0;
}
