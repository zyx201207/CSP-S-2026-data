#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002];
int dfs(int st,int ls,int ns){
	ns &= a[st];
	if(ls == 1)return ns;
	int tmp = 0;
	for(int i = st + 1;i <= n;i++){
		tmp = max(tmp,dfs(i,ls - 1,ns));
	}
	return tmp;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++)cin >> a[i];
	if(m == n){
		int ans = 0x3f3f3f3f;
		for(int j = 0;j < n;j++)ans &= a[j];
		cout << ans;
		return 0;
	}else if(m == 1){
		sort(a,a + n,greater<int>());
		cout << a[0];
		return 0;
	}else if(m == 2){
		int mx = 0;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				mx = max(mx,a[i] & a[j]); 
			}
		}
		cout << mx;
		return 0;
	}else if(n <= 20){
		int tmp = 0;
		for(int i = 0;i < n;i++)tmp = max(tmp,dfs(i,m,0x3f3f3f3f));
		cout << tmp;
		return 0;
	}else cout << 0;
	return 0;
}
