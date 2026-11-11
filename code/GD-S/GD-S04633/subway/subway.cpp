#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long c,n,m,d,q;
long long w[MAXN];
long long g[1010][1010];
void solve1() { //1-6
	memset(g,0x3f,sizeof g);
	long long sta=-1;
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			long long a,t;
			cin>>a>>t;
			sta=max(sta,a+n);
			g[i][a+n]=g[a+n][i]=t;
		}
	}
	//----------floyd
	for(int k=1; k<=sta; k++) {
		for(int i=1; i<=sta; i++) {
			for(int j=1; j<=sta; j++) {
				if(i==j or j==k or k==i)continue;
				if(g[i][j]>g[i][k]+g[k][j]) {
					g[j][i]=g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+g[x+n][y+n]<<"\n";
	}
}
void solve2() { //A
	memset(g,0x3f,sizeof g);
	long long sta=-1;
	for(int i=1; i<=n; i++) {
		long long k,a[3],t[3];
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[j]>>t[j];
			sta=max(sta,a[j]);
		}
		if(k==2)g[a[1]][a[2]]=g[a[2]][a[1]]=t[1]+t[2];
	}
	//----------floyd
	for(int k=1; k<=sta; k++) {
		for(int i=1; i<=sta; i++) {
			for(int j=1; j<=sta; j++) {
				if(i==j or j==k or k==i)continue;
				if(g[i][j]>g[i][k]+g[k][j]) {
					g[j][i]=g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+g[x][y]<<"\n";
	}
}
void solve3() { //B
	memset(g,0x3f,sizeof g);
	long long T,sta=-1;
	vector<int> e[MAXN];
	for(int i=1; i<=n; i++) {
		long long k,a;
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a>>T;
			sta=max(sta,a);
			e[a].push_back(i);
		}
	}
	for(int i=1;i<=sta;i++)
	{
		for(int j=0;j+1<(int)e[i].size();j++)
		{
			g[e[i][j]][e[i][j+1]]=g[e[i][j+1]][e[i][j]]=2;
		}
	}
	//----------floyd
	for(int i=1;i<=n;i++)g[i][i]=1;
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==j or j==k or k==i)continue;
				if(g[i][j]>g[i][k]+g[k][j]) {
					g[j][i]=g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto i:e[x])
		{
			for(auto j:e[y])
			{
				ans=min(ans,w[x]+w[y]+T*g[i][j]+2*T);
			}
		}
		cout<<ans<<"\n";
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	if(c<=6) {
		solve1();
	} else if(c<=11) {
		solve2();
	}
	else if(c<=19)
	{
		solve3();
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
