#include <bits/stdc++.h>
#define N 200011
using namespace std;
typedef long long ll;

int n; ll sum;
struct stru {
    int a;
    char c;
} str[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> str[i].a >> str[i].c;
        sum += str[i].a;
    }
    int l, r;
    ll cnt = 0, pre = 0, x, y;
    for(int i = 1; i <= n; i++) {
        cnt += str[i].a;
        if((sum & 1) == 1) {
            if(cnt > sum / 2) {
                pre = sum / 2 + 1 - pre;
                x = str[i].a - pre;
                y = pre - 1;

                if(x == y) {
                    l = i - 1;
                    r = i + 1;
                    break;
                }

                l = i;
                str[i].a = abs(x - y);
                r = i + (x > y ? -1 : 1);
                if(r < l) swap(l, r);
                break;
            }
        } else if(cnt == sum / 2) {
            l = i, r = i + 1;
            break;
        } else if(cnt > sum / 2) {
            pre = sum / 2 - pre;
            x = str[i].a - pre;
            y = pre;

            if(x == y) {
                l = i - 1;
                r = i + 1;
                break;
            }

            l = i;
            str[i].a = abs(x - y);
            r = i + (x > y ? -1 : 1);
            if(r < l) swap(l, r);
            break;
        }
        pre = cnt;
    }
    ll ans = 0;
    while(l > 0 && r <= n) {
        if(str[l].c != str[r].c)
            ans += min(str[l].a, str[r].a);
        if(str[l].a > str[r].a) {
            str[l].a -= str[r].a;
            r++;
        } else if(str[l].a < str[r].a){
            str[r].a -= str[l].a;
            l--;
        } else l--, r++;
    }
    cout << ans;
    return 0;
}