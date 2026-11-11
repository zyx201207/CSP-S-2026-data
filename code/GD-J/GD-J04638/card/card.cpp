#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int n,m;
int a[500001];
int vis[300010],cnt[300100];
void solve(int l){
	int r = n;
	for(int i = l; i <= r; i++){
		vis[a[i]]++;
		if(vis[a[i]] > 1) {
			while(st.top() != a[i]) st.pop();
		}else{
			st.push(a[i]);
		}
	}
	while(!st.empty()){
		cnt[st.top()]++;
		st.pop();
	}
	for(int i = 1; i <= m; i++) vis[i] = 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		solve(i);
	}
	for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}
