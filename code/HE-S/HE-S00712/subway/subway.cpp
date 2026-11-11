#include <bits/stdc++.h>
using namespace std;

const int M = 5e5+10;
struct line{
	vector<int> a;
	vector<int> t[M];
	int k;
}lines[505];

int c,n,m,d,q;
int w[M],vis[505][M];
queue<pair<int,int>> q;
void bfs(){
	while(!q.empty()){
		int l = q.front().first,z=q.front().second();
		q.pop();
		vis[l][z] = 1;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i<=m) cin >> w[i];
	for (int i = 1;i<n;i++){
		cin >> lines[i].k;
		for (int j = 1;j<=lines[i].k;j++){
			int a,t;
			cin >> a >> t;
			lines[i].a.pushback(a);
			lines[i].t[a] = t;
		}
	}
	for (int i = 0;i<lines[1].a.size();i++){
		q.push({1,lines[1].a[i]});
		vis[1][lines[1].a[i]] = 1;
	}
	bfs();
	return 0;
}
