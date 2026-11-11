#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+5;
int a[N];
int bit_cnt[50];
int n,m,ans;

void rep(int i){
	int val = (1<<i);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] & val){
			a[++cnt] = a[i] - val;
		}
	}
	n = cnt;
}

void sol(){
	memset(bit_cnt,0,sizeof(bit_cnt));
	for(int i = 1; i <= n; i++){
		int val = a[i];
		for(int i = 0; i <= 30; i++){
			if((1<<i) & val) bit_cnt[i]++;
		}
	}
	
	for(int i = 40; i >= 0; i--){
		if(bit_cnt[i] >= m){
			rep(i);
			sol();
			ans += (1<<i);
			return;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("add.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sol();
	cout<<ans;
	return 0;
} 
