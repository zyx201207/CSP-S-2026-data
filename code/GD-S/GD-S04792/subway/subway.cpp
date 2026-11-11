#include <iostream>
#include <fstream>
#include <queue>
#define ll long long
using namespace std;
ll a[201][401];//i号线,从1到j号站需要时间 
ll c,n,m,d,q;
ll w[500005],f[501][501];
ll b[401][21],id[401];
void dfs(ll x,ll y,ll s)
{
	if(f[x][y] < s)return;
	f[x][y] = f[y][x] = s;
	for(int i=0; i<m; i++)
		if(f[y][i] != 1e16)
			dfs(y,i,s+f[y][i]);
	return;
}
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1; i<=n; i++)cin>>w[i];
	for(int i=1; i<=m; i++){
		int k,s=0;cin>>k;
		for(int j=1;j<=k; j++){
			int x,y;cin>>x>>y;
			s+=y;
			b[x][id[x]]=i;
			a[i][x]=s;
			id[x]++;
		}
	}
	for(int i=0; i<500; i++)
	for(int j=0; j<500; j++)
		f[i][j]=1e16;
	for(int i=1; i<=n; i++)
		for(int j=0; j<id[i]; j++)
			for(int k=j+1; k<id[i]; k++){
				f[j][k]=f[k][j]=
				min(f[j][k],
				a[i][b[i][j]]-
				a[i][b[i][j]-1]+
				a[i][b[i][k]]-
				a[i][b[i][k]-1]);
			}
	for(int i=0; i<m; i++)
	for(int j=0; j<m; j++)
		if(f[i][j]!=1e16)
			dfs(i,j,f[i][j]);
	while(q--){
		ll x,y,ans=1e16;cin>>x>>y;
		for(int i=0; i<id[x]; i++)
		for(int j=0; j<id[y]; j++)//和x,y连接的线
			ans=min(ans,f[i][j]);
		cout<<ans+w[x]+w[y]<<'\n'; 
	}
	return 0;
}
