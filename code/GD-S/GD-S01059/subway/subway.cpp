#include<bits/stdc++.h>
#define psb push_back

using namespace std;

typedef long long ll;
template<class T>void Min(T &x,T y) { if (y<x) x=y; }
const ll INF=1e18;
const int N=505,M=500010,MAXD=25;
int n, m, D, Q, w[M];
struct Edge { int t,id; };
Edge vec[M][MAXD]; int idx[M];
ll G[N][N];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int cid; cin >> cid >> n >> m >> D >> Q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++)
	{
		int k; cin >> k; 
		for (int j=0;j<k;j++) 
		{
			int v,t; cin >> v >> t;
			vec[v][idx[v]++]={t,i};
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (j!=i) G[i][j]=INF; 
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<idx[i];j++)
		{
			for (int k=j+1;k<idx[i];k++)
			{
				int t1=vec[i][j].t, u=vec[i][j].id;
				int t2=vec[i][k].t, v=vec[i][k].id; ll wei=t1+t2;
				Min(G[u][v], wei); Min(G[v][u], wei); 
			}
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				Min(G[i][j], G[i][k]+G[k][j]);
	while (Q--)
	{
		int x,y; cin >> x >> y;
		if (x==y) { cout << "0\n"; continue; } 
	
		ll ans=INF;
		for (int j=0;j<idx[x];j++)
		{
			for (int k=0;k<idx[y];k++)
			{
				int t1=vec[x][j].t, u=vec[x][j].id;
				int t2=vec[y][k].t, v=vec[y][k].id; 
				Min(ans,G[u][v]+t1+t2+w[x]+w[y]); 
			}
		}
		cout << ans << "\n";
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

*/

