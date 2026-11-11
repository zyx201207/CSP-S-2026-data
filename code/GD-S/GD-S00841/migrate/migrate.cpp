#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<utility>
using namespace std;
int a[500];
int dd[500];
int ans = 0;
void bfs(int s, int e, int d, int n){
	memset(dd, 0, sizeof dd);
	queue<int> q;
	q.push(s);
	int md = -1;
	int ccnt = 0;
	while(q.size()){
		auto cur = q.front();
		q.pop();;
		if(cur == e){
			ccnt++;
			continue;
		}

		
		for(int i = 1; i <= n; i++){
			if(abs(a[i] - a[cur]) > d || (dd[i] != 0 && dd[cur] + 1 > dd[i])) continue;
			q.push(i);
			dd[i] = dd[cur] + 1;
		}
	}
	if(ccnt > 1) ans++;
}
void solve(){
	ans = 0;
	int n,d;
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			bfs(i,j,n,d);
	cout << ans << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		solve();
	}
}
