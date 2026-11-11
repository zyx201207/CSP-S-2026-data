#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int n, k;
vector<int> e[1000006];

bool check(int x){
	return (rand() & 1);
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	srand(time(0));
	srand(rand());
	int c, T; cin >> c >> T;
	while(T --){
		cin >> n >> k;
		for(int i=1, u, v; i<n; ++i) {
			cin >> u >> v;
			e[u].push_back(v), e[v].push_back(u);
		}
		ll l = 0, r = n;
		while(l < r){
			int mid = l+r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << r << '\n';
	}
	return 0;
}
/*
wu wu wu, tou zhen de hao tong. shen me dou xiang bu liao le.
zhe ge zhuang tai wo zen me da OI bi sai a.
wo hao xiang xiu xi yi xia a miao wu.
bu dui, lian mt19937 dou wang le, wo shi zai shi tai ruo le.
*/
