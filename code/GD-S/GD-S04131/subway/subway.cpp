#include<bits/stdc++.h>
using namespace std;
long long tsq;
long long c,n,m,d,q;
long long w[500001];
vector<long long> bian[501],bian_t[501];
long long u,v;
long long mn=1e12,ans;
long long k[500001];
int vis[500001];
long long a,t;
long long sum=0;
long long last[501][10001];
void dfs(int x,int y)
{
	if(last[x][y]!=0&&ans>=last[x][y]) return;
	last[x][y]=ans;
	if(bian[x][y]==v) {
		mn=min(mn,ans+bian_t[x][y]);
		return;
	}
	for(int i=0;i<k[x];i++) if(vis[bian[x][i]]<=1) {
		vis[bian[x][i]]++;
		dfs(x,i);
		vis[bian[x][i]]--;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		for(int j=0;j<k[i];j++) if(bian[i][j]==bian[x][y]&&(vis[bian[i][j]]<=1)) {
			vis[bian[i][j]]++;
			ans=ans+bian_t[i][j]+bian_t[x][y];
			dfs(i,j);
			ans=ans-bian_t[i][j]-bian_t[x][y];
			vis[bian[i][j]]--;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++) {
			cin>>a>>t;
			bian[i].push_back(a);
			bian_t[i].push_back(t);
		}
	}
	while(q--) {
		scanf("%lld%lld",&u,&v);
		mn=1e12;
		for(int ii=1;ii<=n;ii++) for(int jj=0;jj<k[ii];jj++) last[ii][jj]=0;
		for(int i=1;i<=n;i++) for(int j=0;j<k[i];j++) if(bian[i][j]==u) {
			ans=bian_t[i][j];
			vis[u]=1;
			dfs(i,j);
			vis[u]=0;
		}
		printf("%lld\n",w[u]+w[v]+mn);
	}
}

