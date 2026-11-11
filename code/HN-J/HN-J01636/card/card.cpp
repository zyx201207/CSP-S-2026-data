#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], c[500005]; 
bool f[500005];
stack <int> st;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	if(n == m){
		for(int i = 1;i <= m;i ++) cout << n << " ";
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		memset(f, 0, sizeof(f));
		st.push(0);
		f[0] = 1;
		for(int j = i;j <= n;j ++){
			int x = a[j];
			if(f[x]){
				while(! st.empty() && x != st.top()){
					int t = st.top();
					f[t] = 0;
					st.pop();
				}
				f[st.top()] = 0;
				st.pop();
			}
			st.push(x);
			f[x] = 1;
		}
		while(! st.empty()){
			int t = st.top();
			c[t] ++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i ++) cout << c[i] << " ";
	
	return 0;
}
