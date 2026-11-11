#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],ans,sum,cnt;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef LOCAL
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1,j = 1;i <= n;i++){
		while(a[i] * cnt - sum > m){
			cnt--,sum -= a[j];
			j++;
		}
		ans = max(ans,cnt);
		cnt++,sum += a[i];
	}
	cout << ans + 1;
} 
