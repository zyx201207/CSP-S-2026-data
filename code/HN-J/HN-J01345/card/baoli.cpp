#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
#define __low lower_bound
#define __upp upper_bound
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e3+5;

int n, m, a[N];
int ans[N];

stack<int> st;
bool vis[N];

void doing(int be){
	for(int i = be; i <= n; i++){
		if(vis[a[i]]){
			int y;
			do{
				y = st.top();
				st.pop();
				vis[y] = 0;
			} while(y != a[i]);
		}
		vis[a[i]] = 1;
		st.push(a[i]);
	}
	while(st.size()){
		int x = st.top();
		st.pop();
		ans[x]++, vis[x] = 0;
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		doing(i);
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i];
		if(i != m) cout << " ";
	}
	cout << "\n";
	
	return 0;
}
