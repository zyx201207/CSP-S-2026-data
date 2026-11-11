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

const int N = 5e5+5, M = 3e5+5;

int n, m, a[N];
ll ans[M];

vector<int> ve[N];
int last[M];
int in[N];
ll dp[N];
int add[N];

void jian(){
	for(int i = n; i >= 1; i--){
		if(last[a[i]]) ve[i].pb(last[a[i]]), in[last[a[i]]]++;
		else add[i] = a[i], ve[i].pb(i+1), in[i+1]++;
		last[a[i]] = i;
	}
}

queue<int> q;

void tp(){
	for(int i = 1; i <= n; i++){
		if(!in[i]) q.push(i);
		dp[i] = 1;
	}
	while(q.size()){
		int x = q.front();
		q.pop();
		for(auto y : ve[x]){
			in[y]--;
			dp[y] += dp[x];
			if(!in[y]) q.push(y); 
		}
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	jian();
	tp();
	for(int i = 1; i <= n; i++){
		ans[add[i]] += dp[i];
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i];
		if(i != m) cout << " ";
	}
	cout << "\n";
	
	return 0;
}
