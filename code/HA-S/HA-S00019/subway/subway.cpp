#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e2+10;
const int M=5e5+10;
const int INF=1e18;
int c,n,m,d,q,w[M],k[M],f[N][N]; 
vector<int> a[M],t[M];
map<int,int> mp[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f3f3f3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			a[x].push_back(i),t[x].push_back(y);
			mp[x][i]=y;
		}
	}
	for(int p=1;p<=m;p++)
		for(int i=0;i<a[p].size();i++)
			for(int j=i+1;j<a[p].size();j++)
				f[a[p][i]][a[p][j]]=min(f[a[p][i]][a[p][j]],t[p][i]+t[p][j]),
				f[a[p][j]][a[p][i]]=min(f[a[p][j]][a[p][i]],t[p][i]+t[p][j]);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(j==k) continue;
				if(i==j) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=INF;cin>>x>>y;
		for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++)
				ans=min(ans,f[a[x][i]][a[y][j]]+mp[x][a[x][i]]+mp[y][a[y][j]]);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
