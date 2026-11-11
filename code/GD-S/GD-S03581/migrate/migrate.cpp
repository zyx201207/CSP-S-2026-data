#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int n, d;
int a[N];
int	fr[N], to[N];
int head, tail;
void solve(int tstn){
	cin >> n >> d;
	head = 0, tail = 1;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		head ++;
		while(head >= tail && a[i] - a[tail] > d) tail ++;
		fr[i] = (tail == head + 1 ? 0 : i - tail);
	}
	tail = 0;
	for(int i = 1; i <= n; i ++){
		while(tail <= n && a[tail] - a[i] <= d) tail ++;
		tail --;
		to[i] = tail - i;
	}
	int ans = 0;
//	for(int i = 1; i <= n; i ++){
//		ans += n - to[i] - fr[i];
//	}
	vector<int> wn;
	for(int i = 1; i <= n; i ++){
		if(a[i] - a[1] <= d && a[n] - a[i] <= d){
			wn.push_back(i);
		}
	}
//	if(13 <= tstn && tstn <= 14) 
	if(wn.size() > 2){
		cout << 0 << endl;
	} else if(wn.size() == 2){
		for(int i = 1; i <= n; i ++){
			ans += n - fr[i] - to[i];
		}
		cout << ans << endl;
	} else{
		cout << 0 << endl;
	}
//	if(13 <= c && c <= 14) 
//	for(int i = 1; i <= n; i ++){
//		cout << fr[i] << " " << to[i] << endl;
//	}
}
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--) solve(c);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
