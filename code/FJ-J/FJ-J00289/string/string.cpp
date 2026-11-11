#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;

int n, ans, len;
char ch[maxn];
int a[maxn], st[maxn], ed[maxn], pre[maxn];

int find(int x) {
    int l = 1, r = n, res = n + 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (pre[mid] >= x) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    if (res == n + 1) {
    	return n;
	}
    return res;
}

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> ch[i];
        pre[i] = pre[i - 1] + a[i];
        st[i] = len + 1;
        len += a[i];
        ed[i] = len;
    }
//    for (int i = 1; i <= n; ++i) {
//    	cout << st[i] << " " << ed[i] << "\n";	
//	}
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int c = (len + 1) / 2, l, r;
    if (len % 2) {
        l = c - 1;
        r = c + 1;
    } else {
        l = c;
        r = c + 1;
    }
//    cout << c << " " << l << " " << r << "\n"; 
    while (1 <= l && r <= len) {
        int idl = find(l), idr = find(r);
        int nl = st[idl], nr = ed[idr];
        int lenl = c - nl, lenr = nr - c;
//        printf("%lld %lld %lld %lld %lld %lld %lld %lld ", l, r, idl, idr, nl, nr, lenl, lenr);
        if (ch[idl] == ch[idr]) {
            if (lenl > lenr) {
//            	printf("op1\n");
                r = ed[idr] + 1;
                l = 2 * c - r;
            } else {
//            	printf("op2\n");
                l = st[idl] - 1;
                r = 2 * c - l;
            }
        } else if (lenl > lenr) {
//        	printf("op3 ");
            ans += ed[idr] - r + 1;
//            cout << ed[idr] << " " << r << " ";
//            cout << ed[idr] - r + 1 << "\n";
            r = ed[idr] + 1;
            l = 2 * c- r;
        } else {
//        	printf("op4\n");
            ans += l - st[idl] + 1;
//            cout << ans << "\n";
            l = st[idl] - 1;
            r = 2 * c - l;
        }
    }
    cout << ans;
    return 0;
}
/*
思路：
显然的最暴力的方法是找到回文中心，然后看是用左覆盖右代价小，还是用右覆盖左代价小
显然复杂度是长度，包T
考虑如何加速
如果我们不把字符串展开，而是直接在串块上操作呢
显然的找到一个点所在块是O(logn)的
那么暴力跳块判断是否相同记录答案
nlogn
3 2 a 2 b 1 c
*/
