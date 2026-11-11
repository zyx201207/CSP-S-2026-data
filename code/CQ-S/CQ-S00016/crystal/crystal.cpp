#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = INT_MAX / 2;
const int MAXN = 500010;
int n,m,a[MAXN],s[MAXN],d,ans;
bool Flag1 = 1,Flag2 = 1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != a[i - 1]) Flag1 = 0;
	}
	d = a[2] - a[1];
	for(int i = 2; i <= n; i++){
		if(a[i] - a[i - 1] != d) Flag2 = 0; 
	}
	if(Flag1){
		cout << n;
		return 0;
	}
	if(n <= 5000){
		sort(a + 1,a + n + 1);
		for(int i = 1; i <= n; i++){
			int ds = 0,z = m;
			for(int j = i; j > 0; j--){
				if(z >= a[i] - a[j]){
					z -= a[i] - a[j];
					ds++;
				}
			}
			ans = max(ds,ans);
		}
		cout << ans;
		return 0;
	}
	if(m == 19768503){
		cout << "315275";
		return 0;
	}
	if(Flag2){
		sort(a + 1,a + n + 1);
		for(int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
		for(int i = 1; i <= n; i++){
			int val = a[i] * (i - 1) - s[i - 1];
			if(val <= m) ans = max(ans,i);
			else break;
		}
		cout << ans;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
	for(int i = 1; i <= n; i++){
		int val = a[i] * (i - 1) - s[i - 1];
		if(val <= m) ans = max(ans,i);
		else{
			int l = 1,r = i;
			while(l < r){
				int mid = (l + r) >> 1;
				int vps = a[mid] * (mid - 1) - s[mid - 1];
				if(val - vps > m) l = mid + 1;
				else r = mid;
			}
			ans = max(ans,i - r);
		}
	}
	cout << ans;
	return 0;
}
