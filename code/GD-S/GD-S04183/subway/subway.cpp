#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define id first
#define t second

const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
int k[N];
vector<pii> to[M];
int f[N][N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;

	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) f[i][i]=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;cin>>a>>t;
			for(pii v:to[a])
			{
				int id=v.id,tm=v.t;
				f[id][i]=min(f[id][i],tm+t);
			}
			
			to[a].push_back(mp(i,t));
		} 
	}
		
	for(int len=2;len<=n;len++)
		for(int i=1;i<=n;i++)
		{
			int j=i+len-1;
			for(int k=i;k<=j;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
		
	while(q--)
	{
		int x,y;cin>>x>>y;
		if(x>y) swap(x,y);
		int ans=1e18;
		for(pii u:to[x])
			for(pii v:to[y])
				ans=min(ans,u.t+v.t+f[u.id][v.id]);
		cout<<w[x]+w[y]+ans<<'\n';
	}

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
