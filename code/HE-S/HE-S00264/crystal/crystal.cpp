#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int pre[500010];
int suf[500010];
int js = 0;
int dc = 0;
bool flag2 = 1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
//	for(int i = 1;i<=n;i++){
//		cout << a[i] << "\n";
//	} 
	for(int i = 1;i<=n;i++){
		pre[i] = a[i] - a[i-1];
		if(pre[i] != pre[i-1]) flag2 = 0; 
		suf[i] = (i-1)*pre[i]+suf[i-1];
	}
	if(flag2){
		int ans = 0;
		for(int i = pre[1];m > 0;i+=pre[1]){
			m -= i;
			ans++;
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(suf[i] <= m && suf[i+1] > m){
			cout << i;
			return 0;
		}
	}
	return 0;
} 
