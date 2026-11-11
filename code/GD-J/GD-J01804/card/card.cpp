#include<bits/stdc++.h>
using namespace std;
int a[500007], b[300007];
bool vis[500007];
stack<int> q;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(vis, false, sizeof(vis));
	memset(b, 0, sizeof(b));
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(vis[a[j]]){
				while(q.top() != a[j]){
					vis[q.top()] = false;
					q.pop();
				}
			}else{
				vis[a[j]] = true;
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			vis[q.top()] = false;
			b[q.top()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++){
		cout << b[i] << ' ';
	}
	return 0;
}
