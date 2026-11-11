#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool vis[300005];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(vis,0,sizeof(vis));
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				int u = q.top();
				while(!q.empty() && u != a[j]){
					vis[u] = 0;
					q.pop();
					u = q.top();
				}
				q.pop();
			}
			q.push(a[j]);
			vis[a[j]] = 1;
		}
		while(!q.empty()){
			int u = q.top(); 
			ans[u]++;
			q.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

