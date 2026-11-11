#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
int n;
ll sm , ans;
ll a[N] , sf[N] , nf[N];
char b[N];

int lowbound (ll x) {
	int l = 1 , r = n , cnt = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (nf[mid] <= x) {
            cnt = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return cnt;
}

int main () {
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i] , sm += a[i];
    for (int i = 1; i <= n; i ++)
        sf[i] = sf[i - 1] + a[i];
    nf[n] = sm - a[n] + 1;
    for (int i = n - 1; i; i --)
        nf[i] = nf[i + 1] - a[i];
//    for (int i = 1; i <= n; i ++) {
//		cout << sf[i] << ' ';
//	}
//	cout << "\n";
//	for (int i = 1; i <= n; i ++) {
//		cout << nf[i] << ' ';
//	}
//	cout << "\n\n";
	int rd = 1;
    ll l = 1 , now = 1;
    while (l <= sm / 2) {
        ll r = sm - l + 1;
//        cout << rd << " : \n" << "l and r : " << l << ' ' << r << "\n";
        rd ++;
        int ti = lower_bound(sf + 1 , sf + 1 + n , l) - sf;
        int tj = lowbound(r);
//        cout << "tid : " << ti << ' ' << tj << "\n";
        ll tl = sf[ti] , tr = nf[tj];
        ll ln = tl - l + 1 , rn = r - tr + 1;
//        cout << "length : " << tl << ' ' << tr << ' ' << ln << ' ' << rn << "\n";
        if (ln <= rn) {
            if (b[ti] != b[tj])
                ans += ln;
            l = tl + 1;
        }
        else {
            if (b[ti] != b[tj])
                ans += rn;
            l = l + rn;
        }
//        cout << "\n\n";
        if (l == now)
			break;
		now = l;
    }
    cout << ans;
    return 0;
}

/*
 
3
2 a
2 b
1 c
* 
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*
6
1 a
1 c
2 a
1 b
1 c
1 a
*/
