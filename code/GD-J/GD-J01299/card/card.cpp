#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int vis[N];
int t[N],a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int k = 1;k <= n;k++){
		stack<int> mk;
		for (int i = k;i <= n;i++){
			if(vis[a[i]] != 0){
				while (mk.top() != a[i]){
					vis[mk.top()]--;
					mk.pop();
				}
			}
			else{
				mk.push(a[i]);
				vis[a[i]]++;
			}
		}
		for (int i = 1;i <= m;i++){
			if(vis[i]) t[i]++,vis[i] = 0;
		}
	}
	for (int i = 1;i <= m;i++) cout << t[i] << " ";
	return 0;
}
