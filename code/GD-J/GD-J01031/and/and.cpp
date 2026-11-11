#include<bits/stdc++.h>
#define int long long
#define N 200005

using namespace std;

int n,m,ans;
vector<int>v[2];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1,a;i <= n;i++){
		cin >> a;
		v[1].push_back(a);
	}
	for(int k = 29;k >= 0;k--){
		int num = 0;
		for(int i : v[k % 2]){
			if(i & (1 << k))num++;
		}
		if(num >= m){
			ans |= (1 << k);
			for(int i : v[k % 2]){
				if(i & (1 << k))v[1 - (k % 2)].push_back(i);
			}
		}else{
			for(int i : v[k % 2]){
				v[1 - (k % 2)].push_back(i);
			}
		}
		v[k % 2].clear();
	}
	cout << ans << "\n";
	return 0;
}
