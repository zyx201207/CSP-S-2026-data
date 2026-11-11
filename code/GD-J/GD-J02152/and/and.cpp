#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n, m, a[N], cnt;
int ans;
bool vis[N];
signed main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		vis[i] = 1;
	}
	for(int j = 29; j >= 0; j --){
		cnt = 0;
		for(int i = 1; i <= n; i ++){
			if(vis[i]){
				if((1<<j)&a[i]){
					cnt++;
				}
			}
		}
		if(cnt >= m){
			ans += (1<<j);
			for(int i = 1; i <= n; i ++){
				if(vis[i]){
					if(!((1<<j)&a[i])){
						vis[i] = 0;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
