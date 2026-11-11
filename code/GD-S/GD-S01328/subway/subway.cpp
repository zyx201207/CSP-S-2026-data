#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
vector<vector<int>> line(1005, vector<int>(1005, -1));
vector<int> w(1005);
vector<int> vis(1005, INT_MAX);
vector<vector<int>> path(1005, vector<int>(1005, INT_MAX));
int minn=INT_MAX;

void dfs(int x, int p, int y) {
	if (vis[x]<=p) return;
	if (vis[x]>p) vis[x]=p;
	if (x==y) {
	    minn = min(minn, p);
	    return;
	}
	for (int i=0;i<m;i++) {
		if (path[x][i] != INT_MAX && x!=i) {
		    dfs(i, path[x][i]+p, y);
		}
	}
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	for (int i=0;i<m;i++) {
		cin>>w[i];
	}
	for (int i=0;i<n;i++) {
		int k;
		cin>>k;
		for (int j=0;j<k;j++) {
			int a, b;
			cin>>a>>b;
			a=a-1;
			line[i][a]=b;
		}
	}
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
		if (line[j][i] != -1) {
			for (int k=0;k<m;k++) {
				if (line[j][k] != -1 && k!=i) {
					path[i][k] = min(line[j][k]+w[i]+w[k], path[i][k]);
					path[k][i] = min(line[j][k]+w[i]+w[k], path[k][i]);
				}
			}
		}
		}
	}


	while (q--) {
		int st, y;
		cin>>st>>y;
		st=st-1;
		y=y-1;
		for (int i=0;i<m;i++) vis[i]=INT_MAX;
		minn=INT_MAX;
		dfs(st, 0, y);
		cout<<minn<<endl;
		minn=INT_MAX;
    }
    return 0;
}
