//and
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 7;
int n,m,a[N],ans,mx;
vector<int> vec;
inline void dfs(int st){
	if(vec.size() == m){
		int sum = -1;
		for(int i = 0;i < (int)vec.size();i++) sum = (sum & a[vec[i]]);
		ans = max(ans,sum); return ; 
	}
	for(int i = st;i <= n;i++){
		vec.push_back(i);
		dfs(i + 1);
		vec.pop_back();
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i],mx = max(mx,a[i]);
	if(n <= 20){ // 25pts
		dfs(1);
		cout << ans << endl;
	}
	else if(m == 1){ // 5 pts
		int ans = 0;
		for(int i = 1;i <= n;i++) ans = max(ans,a[i]);
		cout << ans << endl;
	}
	else if(m == n){ // 5pts
		int ans = -1;
		for(int i = 1;i <= n;i++) ans = (ans & a[i]);
		cout << ans << endl;
	}
	else if(m == 2){ // 15 pts 
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans = max(ans,(a[i] & a[j]));
			}
		}
		cout << ans << endl;
	}
	else if(mx < 4){
		map<int,int> mp;
		for(int i = 1;i <= n;i++) mp[a[i]]++;
		int have[4] = {};
		for(int i = 1;i <= n;i++){
			if(a[i] == 3) have[0]++,have[1]++;
			if(a[i] == 2) have[1]++;
			if(a[i] == 1) have[0]++;
		}
		int ans = 0;
		for(int i = 0;i <= 1;i++) if(have[i] >= m) ans += (1 << i);
		cout << ans << endl;
	}
	// 60pts，先这样。 
	return 0;
}
/*
我咋连这题都不会... 
*/
