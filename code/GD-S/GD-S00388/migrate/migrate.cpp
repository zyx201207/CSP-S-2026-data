#include <iostream>

using std::cin;
using std::cout;
using std::cerr;

int C, T;
int n;
long long d, pos[2000006];
int left[2000006];

long long f[2000006], g[2000006];
long long sf[2000006], sg[2000006];

int fast_io = []() {
    cin.tie(0) -> sync_with_stdio(false);
    return 0;
}();

int file_io = []() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    return 0;
}();

int findL(long long x) {
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (pos[mid] < x) l = mid;
        else r = mid;
    } return r;
}

int main() {
    cin >> C >> T;
    
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> pos[i];
            f[i] = 0;
        } g[1] = sg[1] = 1;

        for (int i = 1; i <= n; i++) left[i] = findL(pos[i] - d);

        // long long ans = 0;

        for (int i = 2; i <= n; i++) {
            g[i] = i - left[i] + 1;
            if (i - left[i] == 0) {

            } else if (i - left[i] == 1) {
                f[i] += f[i - 1];
                g[i] += g[i - 1];
            } else {
                int l1 = left[left[i]];
                int l2 = left[left[i] + 1];
                int l3 = left[left[i] + 2];
                if (l1 == left[i] || l2 == left[i]) {
                    goto cont;
                }
                f[i] += sg[l3 - 1] - sg[l2 - 1];
                g[i] += sg[l2 - 1] - sg[l1 - 1];
                f[i] += sf[l2 - 1] - sf[l1 - 1];
            }

            cont: ;
            sf[i] = sf[i - 1] + f[i];
            sg[i] = sg[i - 1] + g[i];
            // if (f[i] < 0 || g[i] < 0) cerr << "ERR\n";
        }

        cout << sf[n] << '\n';
    }
}