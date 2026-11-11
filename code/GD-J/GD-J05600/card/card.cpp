#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5 + 10;
int a[maxn], to[maxn], ans[maxn] = {0};
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    stack<int> st;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
    	memset(to, 0, sizeof(to));
    	for(int j = i; j <= n; j++){
    		if(to[a[j]] == 0){
    			//cout << j;
    			to[a[j]] = 1;
    			st.push(a[j]);
			} else {
				while(st.top() != a[j]){
					to[st.top()] = 0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
		//for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
		//cout << '\n';
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}

