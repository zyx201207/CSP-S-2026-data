#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++) 
#define dwn(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
const int N=700;
int cid,n,m,d,q;
int w[N],K[N];
int f[N][N];
int tot;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cid>>n>>m>>d>>q;
	rep(i,1,m) cin>>w[i];
	memset(f,0x3f,sizeof f);
	tot=m;
	rep(i,1,n)
	{
		cin>>K[i];int x,y;
		tot++;
		rep(j,1,K[i]) cin>>x>>y,f[tot][x]=y,f[x][tot]=y;
	}
	rep(i,1,tot) f[i][i]=0;
	rep(k,1,tot)
		rep(i,1,tot)
			rep(j,1,tot)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int a,b;cin>>a>>b;
		cout<<f[a][b]+w[a]+w[b]<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
