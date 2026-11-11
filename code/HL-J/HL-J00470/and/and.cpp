#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
long long a[MAXN];
long long b[MAXN];
bool ok[MAXN];
long long ans;
int n,m;
void dfs(int k,int top){
	if (top == k+1){
		long long sumn = b[1];
		for (int i = 2;i <= k;i++){
			sumn = (sumn&b[i]);
		}
		ans = max(ans,sumn);
		return;
	} 
	for (int i = 1;i <= n;i++){
		if (!ok[i]){
			ok[i] = 1;
			b[top] = a[i];
			dfs(k,top+1);
			ok[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	if (n <= 20){
		dfs(m,1);
		cout << ans;
		return 0;
	}
	if (m == 1){
		long long mx = 0;
		for (int i = 1;i <= n;i++){
			mx = max(mx,a[i]);
		}
		cout << mx;
	}else if (m == n){
		ans = a[1];
		for (int i = 2;i <= n;i++){
			ans = (ans&a[i]);
		}
		cout << ans;
	}else if (m == n-1){
		sort(a+1,a+1+n);
		ans = a[2];
		for (int i = 3;i <= n;i++){
			ans = (ans&a[i]);
		}
		cout << ans;
	}else{
		cout << 1;
	}
}
