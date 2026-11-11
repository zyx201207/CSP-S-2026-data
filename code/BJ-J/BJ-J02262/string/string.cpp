#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];
char c[N];
string s;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %c", &a[i], &c[i]);

    }
    long long cnt = 0, dead = 0, hou = 0;

    int i = 1, k = n;
    while (i <= n) {
        long long d = min(a[i], a[k]);
        if (c[i] == c[k]) {
            a[i] -= d;
            a[k] -= d;
        }
        else {
            cnt += d;
            a[i] -= d;
            a[k] -= d;
        }

        if (a[i] == 0) {
            i++;
            dead++;
        }
        if (a[k] == 0) {
            k--;
            dead++;
            hou++;
        }
        if (dead == n - 1 || dead == n) {
            break;
        }
    }

    printf("%lld", cnt);
    return 0;
}
