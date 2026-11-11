#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
	int num;
	int xian;
	int t;
};

vector <Node> g[100005];

int tt;
int w[500001],k[501],a[501][500001],t[501][500001],x[100001],y[100001];

int dfs (int start,int end,Node u,int dis){
	if (u.num == end) return dis;
	int ans = INT_MAX;
	
	for (Node i : g[u.num]){
		if (i.xian != u.xian){
			ans = min (ans,dfs (start,end,i,dis + tt));
		}
		else{
			ans = min (ans,dfs (start,end,i,dis));
		}
	}
	
	return ans;
}

signed main(){
//	freopen ("subway.in","r",stdin);
//	freopen ("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	
	for (int i = 1;i <= n;i ++){
		cin >> k[i];
		
		Node last;
		for (int j = 1;j <= k[i];j ++){
			cin >> a[i][j] >> t[i][j];
			tt = t[i][j];
			if (j != 1){
				g[a[i][j]].push_back ({last});
				g[last.num].push_back ({a[i][j],i,tt});
			}
			last = {a[i][j],i,tt};
		}
	}
	
	int ans = INT_MAX;
	for (int i = 1;i <= q;i ++){
		int start,end;
		cin >> start >> end;
		for (Node j : g[x[i]]){
			ans = min (ans,dfs(start,end,j,0) + w[start] + w[end]);
		}
		cout << ans << endl;
	}
	return 0;
}
