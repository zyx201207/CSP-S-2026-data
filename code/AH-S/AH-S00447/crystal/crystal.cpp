#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], diff[N];
int sum;
int ans=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    cin >> n >> m;
    if(n<=5000 && m<=1000000000) {
        for(int i=1; i<=n; i++) {
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        for(int i=1; i<n; i++) {
            diff[i] = a[i+1] - a[i];
        }
        int i=1;
        while(m>0 && i<n) {
            int t = m;
            t -= diff[i]*(i);
            if(t < 0) {
                t = m;
                t /= diff[i];
                for(int k = i+1; k<=n; k++) {
                    if(a[k] == a[i]) t++;
                    else break;
                }
                ans = max(ans, t);
                break;
            }else {
                ans++;
                m = t;
                i++;
                if(m==0) break;
            }
        }
        for(int k = i+1; k<=n; k++) {
            if(a[k] == a[i]) ans++;
            else break;
        }
        cout << ans;
    }else {
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+n+1);
        int l1 = 1, r1 = 1e9, ans1 = 0;
        while(l1 <= r1) {
            int mid = (l1 + r1) / 2;
            if((mid+1)*((mid-1)/(a[2]-a[1])+1) / 2 <= m) {
                ans1 = mid;
                l1 = mid+1;
            }else r1 =mid-1;
        }
        cout << ans1;
    }

	return 0;
}
