#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 2 * 1e5 + 5;
long long a[maxn];
long long t[maxn];
bool vis[maxn];
bool p[maxn];
long long maxx,ans;
long long maxx1,maxx2;
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool flag = true;
	for(int i = 1;i <= n;i++) cin >> a[i];
	maxx1 = a[1],maxx2 = a[2];
	for(int i = 1; i <= n; i++) {
		if(flag == true) {
			long long p = a[i] + 1;
			for(int i = 1; i <= 30; i++) {
				if(pow(2,i) > p) break;
				if(pow(2,i) != p) {
					flag = false;
				}else flag = true;
			}
		}
	}	
//
	if(flag == true) {
		sort(a + 1,a + n + 1,cmp);
		ans = a[1];
		for(int i = 2;i <= m;i++) {
			ans &= a[i]; 
		}
		cout << ans << endl;
		return 0;

	}
	if(m == 1) {
		for(int i = 1; i <= n; i++) {
			maxx = max(maxx,a[i]);
		}
		cout << maxx << endl;
		return 0;
	}
	if(m == n) {
		ans = a[1];
		for(int i = 2; i <= n; i++) {
			ans = (ans & a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	if(m == 2) {
		for(int i = 1;i <= n;i++) {
			for(int j = i + 1;j <= n;j++) {
				ans = max(ans,(a[i] & a[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*4 2
3 7 15 31
*/
