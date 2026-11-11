#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[M];
deque<int> v;
deque<deque<int>> f;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		v.clear();
		for (int j = i; j <= n; j++){
			cout << i << ". ";
			for (auto u : v){
				if (u == a[j]){
					while (v.back() != a[j]){
						v.pop_back();
					}
					v.pop_back();
					break;
				}
			}
		    v.push_back(a[j]);
		    for (auto u : v){
				cout << u << " ";
			}
		    cout << '\n';
		}
		f.push_back(v);
		cout << '\n';
	}
	for (int i = 1; i <= m; i++){
		for (auto u1 : f){
			for (auto u2 : u1){
				if (u2 == i){
					ans[i]++;
				} 
			}
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

/*
HELP!!!
I have nothing to do!!!
Mimukauwa Nicetry.

I will get about 112pts...
There's no hope I can get!
What a disaster!

1 27 6 409 8 4 2 306 7 15 4 15 1 2 2 1 14 264 13 121 15 1 1 4 190 7 1 400 8 6 19 7 2 1 93 13 6 36 2 10 2 3 19 9 5 3 499 20 156 8 10 3 4 71 1 18 1 1 16 91 5 3 3 1 36 1 6 1 1 4 3 1 2 4 22 1 1 21 3 6 2 402 2 1 11 55 1 9 17 6 8 21 14 1 2 107 8 7 10 2 19 5 12 71 1 126 6 3 23 16 1 9 19 3 8 6 1 3 87 9 2 223 2 226 9 10 3 20 2 4 3 59 6 25 3 12 3 1 3 3 1 2 404 2 33 31 25 34 17 5 173 4 32 5 125 3 178 27 11 4 6 303 11 5 5 399 39 9 3 6 129 319 3 249 5 261 2 1 2 4 8 2 30 1 4 10 7 3 1 83 12 36 62 1 2 6 2 7 88 134
1 27 6 409 8 4 2 306 7 15 4 15 1 2 2 1 14 264 13 121 15 1 1 4 190 7 1 400 8 6 19 7 2 1 93 13 6 36 2 10 2 3 19 9 5 3 499 20 156 8 10 3 4 71 1 18 1 1 16 91 5 3 3 1 36 1 6 1 1 4 3 1 2 4 22 1 1 21 3 6 2 402 2 1 11 55 1 9 17 6 8 21 14 1 2 107 8 7 10 2 19 5 12 71 1 126 6 3 23 16 1 9 19 3 8 6 1 3 87 9 2 223 2 226 9 10 3 20 2 4 3 59 6 25 3 12 3 1 3 3 1 2 404 2 33 31 25 34 17 5 173 4 32 5 125 3 178 27 11 4 6 303 11 5 5 399 39 9 3 6 129 319 3 249 5 261 2 1 2 4 8 2 30 1 4 10 7 3 1 83 12 36 62 1 2 6 2 7 88 134

我的这个暴力应该i不会得到太多的分。。。555555555555555 
写完感觉好通透呀! www
      __
      ||
      ||
     O  O


 
*/
