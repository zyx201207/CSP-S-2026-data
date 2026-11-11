#include <bits/stdc++.h>
#define LL long long
using namespace std;
constexpr int N = 2e6 + 10;
int c, t;
int n;
LL d;
LL a[N];
LL same = 1;
LL ans;
LL cnt;

void bfs(int l, int r){
	queue<array<int,2>> qu;
	qu.push({l, 0});
	while(qu.size()){
		auto t = qu.front();
		qu.pop();
		int id = t[0], num = t[1];
//		cout << "now is: " << id << ' ' << num << ' ';
		
		if(id == r){
//			cout << "id == r! ";
			if(cnt == num){
				same++;
//				cout << "ans == num! same = " << same << '\n';
			}
			else if(cnt > num){
//				cout << "cnt > num! cnt = " << cnt << ", num = " << num << '\n';
				cnt = num;
				same = 1;
				
			}
			continue;
		}
		if(a[id + 1] - a[id] > d){
//			cout << "it's not to go!\n";
			continue;
		}
		for(int i = id + 1;i <= r;i++){
			if(a[i] - a[id] > d) break;
			qu.push({i, num + 1});
		}
	}
}

void solve(){
	ans = 0;
	cnt = 1e9;
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n - 3;i++){
		for(int j = i + 3;j <= n;j++){
			cnt = 1e9;
			same = 1;
			bfs(i, j);
			if(same == 2) ans++;
		}
	}
//	cout << n << ' ' << d << ':' << ans << '\n';
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	// special A
	if(c == 11 || c == 12){
		
	}
	
	// special B
	if(c == 13 || c == 14){
		
	}
	
	// special C
	if(c == 15 || c == 16 || c == 17 || c == 18){
		
	}
	
	// others
	while(t--){
		solve();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

