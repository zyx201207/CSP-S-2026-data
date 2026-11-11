#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const int M = 3e5 + 10;
stack<ll> st;
ll a[N], b[M];
bool vis[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = i; j <= n; j++){
			if(!vis[a[j]]){
				st.push(a[j]);
				vis[a[j]] = 1;
			}else{
				while(st.top() != a[j]){
					vis[st.top()] = 0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			b[st.top()]++;
			st.pop();
		}
	}
	
	for(ll i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
	return 0;
}
