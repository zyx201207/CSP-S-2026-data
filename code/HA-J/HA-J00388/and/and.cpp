#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N];
bool failed[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i(1); i <= n; i++){
		cin >> a[i];
		failed[i] = 0;
	}
	
	int ans = 0;
	for(int j(29); ~j; --j){
		int cnt = 0;
		for(int i(1); i <= n; i++){
			if(failed[i]) continue;
			if((((a[i] >> j) & 1)))
				cnt++;
		}
		if(cnt >= m){
			ans += (1 << j);
			for(int i(1); i <= n; i++){ 
				if(failed[i]) continue;
				if(!(((a[i] >> j) & 1)))
					failed[i] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
