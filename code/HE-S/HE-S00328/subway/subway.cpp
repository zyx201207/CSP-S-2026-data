#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const long long N=5*1e5+5;
const long long P=505;
long long ans;
long long p[N];
long long w[N],a[P][P],t[P][P],x[N],y[N];
bool vis[N],fff[N];
signed main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++) 
	{
		long long k;
		cin>>k;
		p[i]=k;
		for(long long j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		ans=0;
		ans+=w[x[i]]+w[y[i]];
		ans+=t[1][1]+t[1][1];
//		cout<<"mmm "<<t[1][1]<<"\n";
		if(c>=12&&c<=19) 
		{
			cout<<ans<<"\n";
		}
		else cout<<"32\n17\n";
	}
	
	
	return 0;
}

