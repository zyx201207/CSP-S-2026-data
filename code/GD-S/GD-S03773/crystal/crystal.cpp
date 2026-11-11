#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 3;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = 1, cnt = 1, tot = 0;
	for(int i = 2,l = 1;i <= n;i++){
		tot += cnt * (a[i] - a[i-1]);
		//cout << tot << " ";
		while(tot > m){
			tot -= (a[i] - a[l++]);
			cnt--;
		}
		//cout << cnt << "\n";
		cnt++;
		if(cnt > ans) ans = cnt;
	}
	cout << ans;
	return 0;
} 
