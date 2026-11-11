#include <algorithm>
#include <fstream>
#include <vector>
constexpr int MAXN = 200'005;

std::ifstream fin("and.in");
std::ofstream fout("and.out");
int n, m;
long long ans;
int a[MAXN];
std::vector<int> vans;

void dfs(int cnt, int k, long long sum) {
    if (cnt == m) {
        ans = std::max(ans, sum);
        return;
    }
    
    for (int i = (k + 1); i <= n; ++i) {
        vans.push_back(a[i]);
        dfs((cnt + 1), i, (sum == -1 ? a[i] : sum & a[i]));
        vans.pop_back();
    }
}

int main(int argc, const char** argv) {
    if (!fin || !fout) return 0;

    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }
    
    dfs(0, 0, -1LL);
    fout << ans << "\n";

    fout.flush();
    return 0;
}