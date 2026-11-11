#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
vector<int>E[200005];
map<int,int>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		for(int j = 0 ; j <= 30 ; j ++){
			if(((a[i] >> j) & 1) == 1){
				E[j].push_back(i);
			}
		}
		mp[i] = 1;
	}
	int ans = 0;
	for(int i = 30 ; i >= 0 ; i --){
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(mp[i])mp[i] = 2;
		}
		for(int j = 0 ; j < E[i].size() ; j ++){
			int x = E[i][j];
			if(mp[x]){
				mp[x] = 1;
				cnt ++;
			}
		}
		if(cnt >= m){
			ans += (1 << i);
		}else{
			continue;
		}
		for(int i = 1 ; i <= n ; i ++){
			if(mp[i] == 2)mp[i] = 0;
		}
	}
	cout << ans;
	return 0;
}
