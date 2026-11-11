#include <bits/stdc++.h>
using namespace std;
int x[2000005],vis[2000005],cnt;
vector<int> s[2000005];
void bfs(int u,int v){
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	int step = 0;
	while(!q.empty()){
		int st = 0;
		int m = q.front();
		q.pop();
		if(vis[m]) continue;
		step++;
		for(int k:s[m]){
			q.push(k);
			vis[k] = true;
			if(vis[v]){
				cnt++;	
				if(cnt == 1){
					st = step;
				}
				else if(step > st) cnt--;
			} 
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		long long n,d;
		cin >> n >> d;
		memset(x,0,sizeof(x));
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		} 
		if(c == 14 || c == 13){
			cout << 0 << '\n';
		}
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n && x[j]-x[i] <= d; j++){
				s[i].push_back(j);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				bfs(i,j);
				if(cnt == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
