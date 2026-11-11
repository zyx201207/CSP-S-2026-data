#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N = 2e5+9;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin>>n>>m;
	vector<int> can;
	for(int i = 1;i <= n;i++) cin>>a[i],can.push_back(a[i]);
	int ans = 0;
	for(int k = 40;k >= 0;k--){
		vector<int> now;
		for(int v : can){
			if((v >> k) & 1){
				now.push_back(v);
			}
		}
		if(now.size() >= m){
			ans += (1 << k),can = now;
		}
	}
	cout<<ans;
	return 0;
}
