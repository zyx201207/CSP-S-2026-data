#include <algorithm>
#include <fstream>
constexpr int MAXN = 500'005;
std::ifstream fin;
std::ofstream fout;

long long n, m;
long long ans;
long long a[MAXN];
long long s[MAXN];

int main(int argc, const char** argv) {
    fin.open("crystal.in");
    fout.open("crystal.out");
    if (!fin || !fout) return 0;

    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }
    std::sort((a + 1), (a + n + 1));
    for (int i = 1; i <= n; ++i) {
        s[i] = a[i] + s[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((a[j] * j - s[j] + s[i - 1]) > m) {
                ans = std::max(ans, static_cast<long long>(j - 1));
            }
        }
    }

    fout << ans << "\n";

    fout.flush();
    fin.close();
    fout.close();
    return 0;
}
