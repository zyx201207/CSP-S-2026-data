#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
/*

*/
typedef long long ll;
const int N = 5e3 + 5;//O(n^2)
int cc, n, cnt, maxn;
ll d;
ll arr[N], dis[N][N];
int head, tail;
pair<ll, ll> q[N];
unordered_map<string, bool> vis;
inline string get(int num){
	string res = "";
	while(num){
		res += (char)((num % 10) ^ 48);
		num /= 10;
	}
	return res;
}
void dfs(int now, int en, int step, string ps){
	if(step > maxn){
		return ;
	}
	if(now == en){
		if(vis.find(ps) == vis.end()){
			++cnt;
			vis[ps] = true;
		}
		else{
//			printf("ps : %s   err!\n", ps.c_str());
		}
		return ;
	}
	ps += '+' + get(now);
//	printf("ps : %s\n", ps.c_str());
	for(int i = 1; i <= d; ++i){
		if(now + i <= en){
			dfs(now + i, en, step + 1, ps);
			if(cnt > 2){
				break;
			}
		}
		else{
			break;
		}
	}
	return ;
}
inline bool check(int a, int b){
	if(dis[a][b] < 0){
		return false;
	}
	cnt = 0;
	maxn = dis[a][b];
	dfs(a, b, 0, "");
//	printf("(%d  %d) : cnt = %d   d = %d\n", a, b, cnt, maxn);
	return cnt == 2;
}
void work(int st){
	head = tail = 0;
	q[tail++] = mp(arr[st], 0);
	dis[st][st] = 0;
	for(int i = st + 1; i <= n; ++i){
		while(head < tail && arr[i] - q[head].first > d){
			++head;
		}
		if(head == tail){
			dis[st][i] = -1;
		}
		else{
			dis[st][i] = q[head].second + 1;
		}
		while(head < tail && q[tail - 1].second > dis[st][i]){
			--tail;
		}
		q[tail++] = mp(arr[i], dis[st][i]);
//		printf("%d ", dis[i]);
	}
	return ;
}
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; ++i){
		work(i);
	}
	vis.clear();
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			if(check(i, j)){
				++ans;
			}
		}
	}
	cout << ans << '\n';
	return ;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _;
	cin >> cc >> _;
	while(_--){
		solve();
	} 
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
