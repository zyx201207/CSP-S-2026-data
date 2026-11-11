#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[300005];
int a[500005];
bool vis[300005];
stack<int> st;
bool flg = 1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] < a[i-1]) flg = 0;
	}
	if(flg){
		for(int i = 1; i <= n; ++i){
			cnt[a[i]] = i;
		}
		for(int i = 1; i <= m; ++i) cout << cnt[i] << " ";
	}else{
		for(int t = 1; t <= n; ++t){
			for(int i = 1; i <= m; ++i) vis[i] = 0;
			for(int i = t; i <= n; ++i){
				if(vis[a[i]] == 0){
					st.push(a[i]);
					vis[a[i]] = 1;
				}else{
					while(1){
						if(st.top() != a[i]){
							vis[st.top()] = 0;
							st.pop();
						}else break;
					}
				}
			}
			while(st.size()){
				cnt[st.top()]++;
				st.pop();
			}
		}
		for(int i = 1; i <= m; ++i) cout << cnt[i] << " ";
	}
	return 0;
}

