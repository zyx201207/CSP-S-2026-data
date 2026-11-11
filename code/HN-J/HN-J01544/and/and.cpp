#include<bits/stdc++.h>
using namespace std;
int n, m, _a, ans;
vector<int> a, nxt;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &_a);
		a.push_back(_a);
	}
	for(int i = 29; i >= 0; i--){
		for(int j : a){
			if((j >> i) % 2){
				nxt.push_back(j);
			}
		}
		if(nxt.size() >= m){
			a = nxt;
			ans += 1 << i;
		}
		nxt.resize(0);
	}
	printf("%d", ans);
	return 0;
}
