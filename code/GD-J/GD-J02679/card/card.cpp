#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	stack<int> s;
	bool vis[300010] = {0};
	int ans[300010] = {0};
	for (int j = 1; j <= n; j++) {
		memset(vis,0,sizeof(vis));
		for (int i = j; i <= n; i++) {
			
			if (!vis[a[i]]){
				s.push(a[i]);
				vis[a[i]] = 1;
			}
			else {
				while (s.top() != a[i]) {
					vis[s.top()] = 0;
					s.pop();
				}
			}
		}
		while (s.size()) {
			ans[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
} 
