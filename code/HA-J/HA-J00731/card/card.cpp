#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[int(5e5+7)];
int last[int(3e5+7)];
int life[int(5e5+7)];
int tmp_t[int(3e5+7)];
int ans[int(3e5+7)];
int next[int(5e5+7)];
bool ok[int(5e5+7)];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n , m; cin >> n >> m;
	
	for (int i = 0 ; i <= m ; ++ i) tmp_t[i] = -1;
	for (int i = 0 ; i < n ;  ++i ) ok[i] = false;
	
	for (int i = 0 ; i < n ; ++ i){
		cin >> a[i];
	}
	
	for (int i = n-1 ; i >= 0 ; -- i){
		next[i] = tmp_t[a[i]];
		tmp_t[a[i]] = i;
	}
	
	for (int i = 0 ; i < n ; ++ i){
		if (ok[i] == true){
			ans[a[i]] = max(ans[a[i]],life[i]);
			continue;
		}
		int pos = i;
		int deep = 1;
		while (pos < n){
			for (;next[pos] != -1 ; pos = next[pos]) life[pos] += deep;
			life[pos ++] += deep;
			if (ok[pos] == false) ++ deep;
			if (pos < n) ok[pos] = true;
		}
		ans[a[i]] = max(ans[a[i]],life[i]);
	}
	
	for (int i = 1 ; i <= m ; ++ i){
		cout << ans[i] << " ";
	}
	
	return 0;
}
