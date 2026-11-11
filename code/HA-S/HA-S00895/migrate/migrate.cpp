#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int c, t;
int n;
ll d, ans = 0, mink = LLONG_MAX;

void dfs(int pos, int end, ll dis, int k, vector <ll> &x){
	if(k > mink) return ;
	if(pos == end){
		if(mink > k){
			ans = 0;
			mink = k;
		}else{
			if(mink == k){
				++ans;
			}
		}
		return ;
	}
	for(int i = pos+1; i < end && dis >= abs(x[i+1] - x[i]); ++i){
		dis -= abs(x[i+1] - x[i]);
		dfs(i+1, end, d, k+1, x);
	}
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//  remember to freopen!!!!!!!!!!!!!!!
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		vector <ll> x(n+1);
		for(int i = 1; i <= n; ++i){
			cin >> x[i];
		}
		int aans = 0;
		for(int l = 1; l < n-2; ++l){
			for(int r = l + 3; r <= n; ++r){
				ans = 0;
				mink = LLONG_MAX;	
				dfs(l, r, d, 0, x);
				if(ans == 1) ++aans;
			}
		}
		cout << aans << "\n";
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1


*/

