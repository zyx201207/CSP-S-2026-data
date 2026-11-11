#include <bits/stdc++.h>
using namespace std;
int a[500005];
int lst[300005];
int ans[300005];
int cnt[500005];
int skp[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		lst[a[i]] = i;
	}
	int curr = 1;
	for(int i = 1; i <= n; i++){
		if(lst[a[i]] == i) skp[curr] = i;
		else {
			skp[curr = i] = i;
			curr ++;
		}
	}
	for(int i = 1; i <= n; i++){
		if(skp[i]) curr = skp[i];
		else {
			skp[i] = curr;
		}
	}
	for(int i = 1; i <= n; i++){
		int nxt = i;
		while(nxt <= n){
			int t = skp[nxt];
			cnt[nxt]++; 
			cnt[t + 1]--;
			nxt = lst[a[t]] + 1;
		}
	}
	for(int i = 1; i <= n; i++){
		cnt[i] += cnt[i - 1];
		ans[a[i]] += cnt[i];
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
} 
