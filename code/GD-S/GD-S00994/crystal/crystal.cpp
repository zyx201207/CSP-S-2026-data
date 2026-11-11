#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 5e5 + 5;

bool bst;
int n,m,ans;
int a[N],pre[N];
bool bed;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 1;i <= n;i++){
		int l = 1,r = i,mid,res = 0;
		while (l <= r){
			mid = (l + r) >> 1;
			if ((i - mid + 1) * a[i] - pre[i] + pre[mid - 1] <= m) res = mid,r = mid - 1;
			else l = mid + 1;
		}ans = max(ans,i - res + 1);
	}cout << ans << "\n";
	return 0;
}
/*
5 8 
-3 -1 2 2 7
*/ 
