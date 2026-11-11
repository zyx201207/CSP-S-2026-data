#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
const int N=5e5+5;
int c,n,m,d,q;
ll w[N],ans=1e18;
int a[505][200005],t[505][200005];
int f[N][505];
vector<int> v[N];
vector<bool> vis(N);
void dfs(int qx,int zx,ll cnt){
	if(qx==zx){
		ans=min(ans,cnt);
		return ;
	}
	vis[qx]=1;
	for(auto e:v[qx]){
		if(vis[e]) continue;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j && f[qx][i] && f[e][j]){
					cnt=cnt+t[i][f[qx][i]]-t[j][f[qx][j]];
					vis[e]=1;
					dfs(e,zx,cnt);
					cnt=cnt-t[i][f[qx][i]]-t[j][f[e][j]];
					vis[e]=0;
				}
			}
		} 
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(a[i][j-1]);
			v[a[i][j-1]].push_back(a[i][j]);
			f[a[i][j]][i]=j;
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		ans=1e18;
		dfs(xr,yr,w[xr]+w[yr]);
		cout<<ans<<endl;
	}
    return 0;
}
