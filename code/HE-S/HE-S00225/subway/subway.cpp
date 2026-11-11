#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+10;
ll c,n,m,d,q,w[M],a[505][5005],k[505],t[505][5005],x,y,b[4005][4005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	memset(b,0x3f,sizeof b);
	for(int i=1;i<=1000;++i) b[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k[i];++j)
			for(int g=j+1;g<=k[i];++g)
				b[a[i][j]][a[i][g]]=b[a[i][j]][a[i][g]]=t[i][j]+t[i][g];
	for(int g=1;g<=m;++g)
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j)
				b[i][j]=min(b[i][j],b[i][g]+b[g][j]);
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		cout<<min(b[x][y],b[y][x])+w[x]+w[y]<<"\n";
	}
	return 0;
}
