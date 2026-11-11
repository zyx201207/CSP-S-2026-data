#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N];
int ans[N];
bool vis[N];
deque <int> dsk;
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				while(!dsk.empty()){
					if(dsk.back() != a[j]){
						vis[dsk.back()] = 0;
						dsk.pop_back();
					}else{
						dsk.pop_back();
						break;
					}
				}
			}
			dsk.push_back(a[j]);
			vis[a[j]] = 1;
		}
		while(!dsk.empty()){
			ans[dsk.back()]++;
			vis[dsk.back()] = 0;
			dsk.pop_back();
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
