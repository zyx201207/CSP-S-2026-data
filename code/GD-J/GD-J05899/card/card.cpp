#include<bits/stdc++.h>
using namespace std;
int a[500010];
int cnt[300010];
bool is[300010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		memset(is, 0, sizeof(is));
		stack<int> st;
		for(int j = i; j <= n; j++){
			if(is[a[j]]){
				while(!st.empty()){
					if(st.top() == a[j]) break;
					is[st.top()] = false;
					st.pop();
				}
			}else{
				st.push(a[j]);
				is[a[j]] = true;
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}
