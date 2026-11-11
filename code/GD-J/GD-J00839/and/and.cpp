#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n , m;
long long a[N];
int s[N];
int h[N];
long long vis[N];
long long box[N];
long long ans = 0;
void dfs(int x , int last){
	if(x > m){
		int sum = 0;
		for(int i = 1; i <= m; i++){
			if(i != 1) box[i] = box[i] & box[i - 1];
		}
		ans = max(ans , box[m]);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i] && last <= a[i]){
			box[x] = a[i];
			vis[i] = 1;
			dfs(x + 1 , a[i]);	
			box[x] = 0;
			vis[i] = 0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	dfs(1 , 0);
	cout << ans;
	return 0;
}
