#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], i, j;
bool vis[N];
map<ll, ll> mp;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for (i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		stack<ll> st; 
		for (j = i; j <= n; j++){
			if (vis[a[j]] == 0){
				vis[a[j]] = 1;
				st.push(a[j]);
			}else{
				while(!st.empty()){
					if (st.top() == a[j]){
						st.pop();
						break;
					}
					vis[st.top()] = 0;
					st.pop();
				}
				st.push(a[j]);
				vis[st.top()] = 1;
			}
		}
		while(!st.empty()){
			mp[st.top()]++;
			st.pop();
		}
	}
	for (auto e : mp){
		printf("%lld ", e.second);
	}
	return 0;
} 
