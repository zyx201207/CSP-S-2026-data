#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long c,n,m,d,q,w[N],na[N][510],ans;
/*struct node
{
	long long a,t;
}st[510][510];
bool cmp(node x,node y)
{
	return x.a<y.a;
}*/
long long check(long long x,long long i,long long y)
{
	for(int j=1;j<=n;j++)
	{
		if(na[y][j]!=0) return na[x][i]+na[y][i];
	}
	for(int j=1;j<=n;j++)
	{
		if(na[x][j]!=0&&j!=i) return check(x,i,y)
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{
		long long k,a;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>na[a][i];//[a] zandian;[i] xianlu 
	}
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int i=1;i<=n;i++)
		{
			if(na[x][i]!=0) ans=min(check(x,i,y),ans);
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
