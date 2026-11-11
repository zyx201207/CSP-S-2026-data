#include<bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const long long inf = LONG_LONG_MAX;
long long a[maxn];
bool vis[maxn];
int lg[22];
long long ans = 0;
int n,m;
void dfs(int dep,long long sum){
	if(dep == m){
		ans = max(ans,sum);
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = true;
		dfs(dep + 1,sum & a[i]);
		vis[i] = false;
	}
}
bool check(int num){
	if(num == 1){
		bool all_ok = true;
		for(int i = 1;i <= n;i++){
			bool ok = false;
			for(int j = 1;j <= 20;j++){
				if(lg[j] == a[i] + 1){
					ok = true;
					break;
				}
			}
			if(!ok){
				all_ok = false;
				break;
			}
		}
		if(all_ok) return true;
		else return false;
	}
}
void pass(){
	ans = inf;
	sort(a + 1,a + n + 1);
	int tmp = 0;
	for(int i = n;i >= 1;i--){
		tmp++;
		ans = ans & a[i];
		if(tmp >= m) break;
	}
	cout << ans << '\n';
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	lg[0] = 1;
	for(int i = 1;i <= 20;i++){
		lg[i] = 2 * lg[i - 1];
	}
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	//小数据(测试点1-5)
	if(n <= 20){
		ans = 0;
		dfs(0,inf);
		cout << ans << '\n';
	}
	//m=1(测试点6)
	else if(m == 1){
		ans = 0;
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
		cout << ans << '\n';
	}
	//m=n(测试点7)
	else if(m == n){
		ans = inf;
		for(int i = 1;i <= n;i++){
			ans = ans & a[i];
		}
		cout << ans << '\n';
	}
	//m=2(测试点8-10)
	else if(m == 2){
		ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans << '\n';
	}
	//特殊性质A 
	else if(check(1)){
		ans = inf;
		sort(a + 1,a + n + 1);
		int tmp = 0;
		for(int i = n;i >= 1;i--){
			tmp++;
			ans = ans & a[i];
			if(tmp >= m) break;
		}
		cout << ans << '\n';
	}
	//正解 
	else{
		pass();
	} 
	return 0;
}
