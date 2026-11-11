#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500050];
int cnt[300030];
unordered_map<int, int> mp;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
    for(int i = 1; i <= n; i++){
		cin >> a[i];
        cnt[a[i]] += i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(mp[a[j]]){
                for(int k = mp[a[j]]; k <= j - 1; k++){
                    cnt[a[k]]--;
                }
				mp.clear();
            }
            mp[a[j]] = j;
        }
        mp.clear();
    }
    for(int i = 1; i <= m; i++){
        cout << cnt[i] << " ";
    }
}
//10 3
//3 1 2 1 3 2 3 1 2 1
