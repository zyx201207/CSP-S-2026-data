#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10,INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N],s[N];
bool check(int i,int j){
	int sum = s[i] - s[j - 1];
	int len = i - j + 1;
	int res = len * a[i];
	return res - sum <= m;
}
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++) s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n;i ++){
		int l = 1,r = i,cur = INF;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(i,mid)){
				cur = min(cur,mid);
				r = mid - 1;
			}else {
				l = mid + 1;
			}
		}
		ans = max(ans,i - cur + 1);
	} 
	cout << ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
