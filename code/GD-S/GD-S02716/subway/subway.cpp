#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+8;
const int mod =998244353;
#define ll long long
int w[mx];
long long f[508][508];
vector<int> t[mx];
vector<int> g[mx];
ll ans;
void solve(){
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e18;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		f[i][i]=0;
		cin>>k;
		for(int j=1,ai,ti;j<=k;j++){
			cin>>ai>>ti;
			t[ai].push_back(ti);
			g[ai].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(g[i].size()<=1)continue;
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
//				cout<<i<<" "<<g[i][j]<<" "<<g[i][k]<<" "<<t[i][j]<<" "<<t[i][k]<<'\n';
				f[g[i][j]][g[i][k]]=min(f[g[i][j]][g[i][k]],1ll*(t[i][j]+t[i][k]));
				f[g[i][k]][g[i][j]]=f[g[i][j]][g[i][k]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
			}
//			cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,1ll*(t[x][i]+t[y][j]+f[g[x][i]][g[y][j]]+w[x]+w[y]));
			}
		}
		cout<<ans<<'\n';
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1,c;
//	cin>>t;
	cin>>c;
	while(t--){
		solve();
	}
	return 0;
}


