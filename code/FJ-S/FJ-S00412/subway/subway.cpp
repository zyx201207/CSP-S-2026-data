#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+5;
int c,n,m,d,q,w[maxn],t[505][maxn],vis[maxn],fa[maxn];
vector<pair<int,int>> e[maxn];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){//每条路线 
		int k;
		cin >> k;
		for(int x=1;x<=k/2;x++){//具体地铁站 
			int j,r;
			cin >> j >> r;
			vis[j] = 1;
			t[i][j] = r;
			if(!vis[i]){
				fa[j] = i;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin >> s >> e;
		cout << w[s] + w[e] + t[fa[s]][s] + t[fa[s]][e] << endl;
 	}
	return 0;
}
