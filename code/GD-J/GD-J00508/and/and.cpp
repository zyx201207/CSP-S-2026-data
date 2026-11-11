#include<bits/stdc++.h>
using namespace std;
int n,m;
int Max = 0,ans = 0,ans1 = 0,maxx = 0;
int a[2010];
int a1[2010]; 
bool vis[2010];
void dfs(int u){
	if(u > m){
		ans1 = a1[1];
		for(int i = 2;i <= m;i++){
			ans1 = (ans1&a1[i]);
		}
		maxx = max(maxx,ans1);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == 0){
			vis[i] = 1;
			a1[u] = a[i];
			dfs(u+1);
			a1[u] = 0;
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	Max = a[1];
	ans = a[1];
	for(int i = 2;i <= n;i++){
		cin >> a[i];
		Max = max(a[i],Max);
		ans = (ans&a[i]);
	}
	if(n <= 2000){
		if(m == 1){
			cout << Max;
		}
		else if(m == 2){
			dfs(1);
			cout << maxx;
		}
		else if(m == n){
			cout << ans;
		}
		else if(n <= 20 && m <= n){
			dfs(1);
			cout << maxx;
		}
	}
	else{
		cout << 0;
	}
	return 0;
} 
