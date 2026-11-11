#include <bits/stdc++.h>
using namespace std;
int w[500005],k[505],n,a[505][500005],t[505][500005],x[100005],y[100005],d=0,v[500005],ans=0;

	vector <int> g[100005];
void dfs(int u,int zh){
	v[u]=1;
	if (u==zh) return;
	for (int o:g[u]){
		if (!v[o]) {
			
			int l=0;
			for (int i=1;i<=n;i++){
				int r=0;
				for (int j=1;j<=k[i];j++){
					if (a[i][j]==u) r++;
					if (a[i][j]==o) r++;
				}
				if (r==2)l++;
			}
			if (l==0) d++;
			
			dfs(o,zh);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	long long c,m,d,q;
	cin>>c>>n>>m>>d>>q ;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if (j!=1){
				g[a[i][j]].push_back(a[i][j-1]);
				g[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	for (int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans=w[x[i]];
		dfs (x[i],y[i]);
		ans+=w[y[i]];
		ans=ans+(d+2)*t[1][1];
		cout<<ans<<endl;
		d=0;
		for (int j=1;j<=500003;j++) v[j]=0;
		vector <int> g[100005];
	}
	
	return 0;
}
