#include <iostream>
#include <vector>
int n;
struct input {
    int a;
    char c;
};
long long sum = 0, _index = 0, ous = 0, cous = 0;
int ij = 2;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::vector<input> v(n + 1);
    std::cin >> v[1].a >> v[1].c;
    sum = v[1].a;
    for (int j = 2; j <= n; j++) {
        std::cin >> v[ij].a >> v[ij].c;
        sum += v[ij].a;
        if (v[ij].c == v[ij - 1].c) {
            v[ij - 1].a += v[ij].a;
            ij--;
        }
        ij++;
    }
    auto z = [&v](long long p) {
        long long summ = 0;
        for (int i = 1; i <= n; i++) {
            summ += v[i].a;
            if (p <= summ) {
                return v[i].c;
            }
        }
        return '\0';
    };
    bool gus = true;
    for (int i = 1, j = n; i < j; i++, j--) {
        if (v[i].a == v[j].a) {
            if (v[i].c != v[j].c) {
                cous += v[i].a;
            }
        }
        else {
            gus = false;
            break;
        }
    }
    if (gus == true) {
        std::cout << cous << '\n';
        return 0;
    }
    for (long long i = 1, j = sum; i < j; i++, j--) {
        if (z(i) != z(j)) {
            ous++;
        }
    }
    std::cout << ous << '\n';
    return 0;
}