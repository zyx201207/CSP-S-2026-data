#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int N = 2e5 + 10;
const int M = 2e8 + 5;
int n,m;
int a[N];
int cnt[M];
int ans = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and3.in", "r", stdin);
	freopen("and3.out", "w", stdout);
	cin >> n >> m;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n ; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a + 1, a + 1 + n);
	for(int i = n; i >= 1; i--){
		if(cnt[a[i]] >= m){
			ans = max(ans, a[i]);
		}
		else{
			int nows = a[i];
			int nowid = i;
			int len = m - cnt[a[i]];
			while(len--){
				if(nowid > 1){
					nowid--;
				nows &= a[nowid];
				}
				else{
					nows = -1;
					break;
				}
			}
			ans = max(ans, nows);
		}
	}
	cout << ans;
	return 0;
}
