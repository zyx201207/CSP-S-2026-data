#include<bits/stdc++.h>
using namespace std;
#define unsigned int long long
//怎么就挂了。哎
//所谓的幸福 其实哪里都找不到啊 
//窝巢你大爷的忘排序了我调了两个小时差点他吗哭了 
int dif[500010];
int a[500010];
int ch[500010];
int q[500010];
unordered_map<int , int> mp;
int n , m;
bool check(int j , int i){
//	cout << j << ' ' << i << ' ' << ch[i] - a[i] * (j - 1) + q[j - 1] << '\n';
	if(i == j) return 1;
	if(j == 1){
		if(ch[i] <= m) return 1;
		return 0;
	}
	if((__int128)ch[i] - (__int128)a[i] * (j - 1) + q[j - 1] <= (__int128)m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	for(int i = 1;i < n;i ++) dif[i] = a[i + 1] - a[i] , q[i] = q[i - 1] + a[i];
	int ans = 0;
	for(int i = 1;i <= n;i ++) mp[a[i]] ++ , ans = max(ans , mp[a[i]]);
	for(int i = 2;i <= n;i ++) ch[i] = ch[i - 1] + (i - 1) * dif[i - 1];
	for(int i = 1;i <= n;i ++){
		int l = i , r = n;
		while(l < r){
			int mid = (l + r + 1) >> 1; 
			if(check(i , mid)) l = mid;
			else r = mid - 1;
		}
		ans = max(ans , l - i + 1);
	}
	cout << ans;
	return 0;
}
