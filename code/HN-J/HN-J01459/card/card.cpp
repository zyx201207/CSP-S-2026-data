#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 150005;
const int M = 1505;
const int INF = 1e9;
const int mod = 998244353;
int a[N], sum[N];
void work(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		unordered_map<int, int> mp, num;
		for(int j = i; j <= n; j++){
			if(mp[a[j]]){
				for(int l = mp[a[j]] + 1; l <= cnt; l++){
					mp[num[l]] = 0;
				}
				cnt = mp[a[j]];
			}else{
				num[++cnt] = a[j];
				mp[a[j]] = cnt;
			}
		}
		for(int j = 1; j <= n; j++){
			if(mp[a[j]]){
				sum[a[j]] ++;
				mp[a[j]] = 0;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << sum[i] << " ";
	}
	return ;
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --){
		work();
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/ 
//luogu uid:910628 球上神人共赏
