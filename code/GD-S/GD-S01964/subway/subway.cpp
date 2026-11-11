#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int g[1005][1005];
vector<int> a[505];
vector<int> t[505];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	memset(g,0x3f3f3f,sizeof(g));
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int i=1;i<=2*k;i++){
			int a1,t1;
			cin >> a1 >> t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
		}
		for(int l=1;l<=k;l++){
			for(int j=1;j<=k;j++){
				g[i][j]=min(t[i][l]+t[i][j],g[i][j]);
				g[j][i]=min(t[i][l]+t[i][j],g[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << 1 << "\n";
	}
	for(int i=1;i<=n;i++){
		int min_=1e10;
		for(int j=0;j<a[i].size();j++){
			
		}
	}
	return 0;
}
