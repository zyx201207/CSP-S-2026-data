#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], res[N];
bool vis[N];
int n, m;
queue<int> q;
queue<int> q2;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		for(int j = i; j <= n; j++){
			if(vis[a[j]] == 0){
				q.push(a[j]);
				vis[a[j]] = 1;
			}else{
				while(q.front() != a[j]){
					q2.push(q.front());
					q.pop();
				}
				while(!q.empty()){
					vis[q.front()] = 0;
					q.pop();
				}
				while(!q2.empty()){
					q.push(q2.front());
					q2.pop();
				}
				q.push(a[j]);
				vis[a[j]] = 1;
			}
		}
		while(!q.empty()){
			res[q.front()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << res[i] << ' ';
	return 0;
}
