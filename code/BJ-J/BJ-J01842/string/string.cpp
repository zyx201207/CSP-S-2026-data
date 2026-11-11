#include <cstdio>
#include <iostream>

using namespace std;

unsigned long long a[200005];
char c[200005];
int n;

char get_char(__uint128_t pos) {
    if (pos < 0) {
        throw "Invalid input!";
    }
    for (int i = 0; i < n; i++) {
        if (pos < a[i]) {
            return c[i];
        }
        pos -= a[i];
    }
    throw "Input out of range!";
}

void put_uint128(__uint128_t i) {
    if (i < 10) {
        cout << static_cast<int>(i) << endl;
        return;
    }
    put_uint128(i / 10);
    put_uint128(i % 10);
}

int main() {
    freopen("./string.in", "r", stdin);
    freopen("./string.out", "w", stdout);
    __uint128_t last = 0, start = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
        last += a[i];
    }
    last--;
    while (start < last) {
        if (get_char(start) != get_char(last)) {
            count++;
        }
        start++;
        last--;
    }
    put_uint128(count);
    cout << endl;
    return 0;
}
