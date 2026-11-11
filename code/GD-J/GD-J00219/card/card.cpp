#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
// for m <= 3000
int cnt[3005];
int pos[3005];
int ans[3005];
//
// for case 20
int lst[200005];
//
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	
	if(m <= 3000){
		vector< bitset<3005> > bs(n + 5, 0);
		vector< bitset<3005> > all(m + 5, 0);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			cnt[a[i]]++;
		}
		for(int i = n; i >= 1; i--){
			if(pos[a[i]] == 0){
				bs[i] = bs[i + 1];
				bs[i][a[i]] = 1;
				all[a[i]] = bs[i];
				pos[a[i]] = i;
			}
			else{
				bs[i] = bs[pos[a[i]]];
			}
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				ans[j] += all[i][j] * cnt[i];
			}
		}
		
		for(int i = 1; i <= m; i++){
			cout << ans[i];
			if(i != m){
				cout << " ";
			}
		}
		cout << "\n";
	}
	else{
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			lst[a[i]] = i;
		}
		for(int i = 1; i <= m; i++){
			cout << lst[i];
			if(i != m){
				cout << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}
