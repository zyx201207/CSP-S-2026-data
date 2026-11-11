#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010], sum[300010], vis[300010];
int main(){
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof vis);
		for(int j = i; j <= n; j++){
			if(vis[a[i]]){
			}else{
				vis[a[i]]=1;
				sum[a[i]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << sum[i] << " ";
	}
	return 0;
}