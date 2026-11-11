#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int N = 5e5 + 3, M = 3e5 + 3;
int n, a[N], m;
//
int res[M];
int t[N], r;
int pos[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	for(int i = 1;i <= n;++i){
		r = 0;
		memset(pos, -1, sizeof pos);
		for(int j = i;j <= n;++j){
			if(pos[a[j]] != -1){
				int k = pos[a[j]], tmp = k;
				for(;k <= r;++k){
					pos[t[k]] = -1;
				}
				r = tmp - 1;
			}
			t[++r] = a[j];
			pos[a[j]] = r;
		}
		for(int j = 1;j <= r;++j){
			++res[t[j]];
		}
	}
	cout << res[1];
	for(int i = 2;i <= m;++i){
		cout << ' ' << res[i];
	}
	cout << '\n';
	return 0;
}
