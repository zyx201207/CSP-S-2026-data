#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, a[N];
char c[N];
ll ans = 0, l, r;
bool flag = 1;
int main() { // x x xxx ----- Xterfusion
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)  {
        scanf("%d %c", &a[i], &c[i]);
        if(i != 1 && c[i] != c[i - 1]) flag = 0;
    }
    if(n == 1 || flag) {
        cout << 0 ;
        return 0;
    }
    l = 1;
    r = n;
    while(l < r) {
        if(c[l] != c[r]) {
            if(a[l] == a[r]) {
                ans += a[l];
                l++;
                r--;
            } else if(a[l] < a[r]) {
                ans += a[l];
                a[r] -= a[l++];
            } else {
                ans += a[r];
                a[l] -= a[r--];
            }
        } else {
            if(a[l] == a[r]) {
                l++;
                r--;
            } else if(a[l] < a[r]) a[r] -= a[l++];
            else a[l] -= a[r--];
        }
    }
    printf("%lld", ans);
    return 0;
}

