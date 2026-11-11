#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
	{
		int x,q;
		cin>>x>>q;
		long long ans=0;
		ans+=(w[x]+w[q]);
		ans+=t[x][x]+t[x][x+1]+t[x+1][x+1]+t[x+1][x+2];
		cout<<ans<<endl;
	}
	return 0;
}
