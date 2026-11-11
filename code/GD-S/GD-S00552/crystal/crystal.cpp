#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

const int N = 500005;
int n;
long long a[N],m;
long long s[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i-1] + a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int L = 1,R = i,res = 1;
		while(L <= R){
			int mid = L + R >> 1;
			if(1ll * mid * a[i] - (s[i] - s[i-mid]) <= m) res = mid,L = mid + 1;
			else R = mid - 1;
		}
		ans = max(ans,res);
	}
	cout << ans;
	return 0;
}