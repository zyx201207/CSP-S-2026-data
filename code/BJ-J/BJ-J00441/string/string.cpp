#include <iostream>
#include <cstring>
using namespace std;

long long a[214514];
int s[27];
char c[241514];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int ace = 0, cur = 1;
    int n; cin >> n;
    int m = n;
    for (int i = 1; i <= n; i++){
        int aa; char cc; cin >> aa >> cc;
        if (c[ace] == cc){
            a[ace] += aa;
            cur--, m--;
        }
        else{
            ace = cur;
            a[cur] = aa, c[cur] = cc;

        }
        cur++;
    }
    int l = 1, r = m;
    long long ans = 0;
    while (l < r){
        if (l >= r) break;
        //l = i, r = n - i + 1;
        if (c[l] == c[r]){
            if (a[l] > a[r]){
                a[l] -= a[r]; a[r] = 0;
                r--;
            }
            else if (a[l] < a[r]){
                a[r] -= a[l]; a[l] = 0;
                l++;
            }
            else if (a[l] == a[r]){
                a[r] = 0; a[l] = 0;
                l++, r++;
            }
        }
        else{
            if (a[l] > a[r]){
                ans += a[r];
                a[l] -= a[r]; a[r] = 0;
                r--;
            }
            else if (a[l] < a[r]){
                ans += a[l];
                a[r] -= a[l]; a[l] = 0;
                l++;
            }
            else if (a[l] == a[r]){
                ans += a[l];
                a[r] = 0; a[l] = 0;
                l++, r++;
            }
        }
        if (l >= r) break;
    }
    cout << ans;
    return 0;
}
