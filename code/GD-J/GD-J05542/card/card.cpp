#include<bits/stdc++.h>
using namespace std;
int n,m,a[300001];
bool vis[10001];
stack<int> st;
int ans[3000001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j = i;j<=n;j++){
			if(vis[a[j]]){
				while(!st.empty() && st.top() != a[j]){
					vis[st.top()] = 0;
					st.pop();
				}
			}else{
				st.push(a[j]);
				vis[a[j]] = 1;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
