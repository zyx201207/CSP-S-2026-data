#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e6+5;

int c, t;
int n, d, x[N], dp[N], mini[N];

void dfs(int u, int cnt) {
    if (cnt > mini[u])
        return;
    else if (cnt < mini[u]) {
        // 应该是不可能的，但写上
        dp[u] = 0;
    }
    mini[u] = cnt;
    if (cnt == mini[u])
        ++dp[u];
    int upper = upper_bound(x + 1, x + 1 + n, x[u] + d) - x - 1;
    for (int i = upper; i >= u + 1; --i)
        dfs(i, cnt + 1);
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        fill(dp + u, dp + 1 + n, 0);
        fill(mini + u, mini + 1 + n, 1e18);
        dfs(u, 0);
        for (int v = u + 1; v <= n; ++v)
            if (dp[v] == 2)
                ++cnt;
    }
    cout << cnt << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
        solve();
    return 0;
}

/**
 * 估测：100+44+24+0=168 pts（通过大样例）
 * 通过 //freopen && // freopen、退役让你找到我的代码
 * 我的洛谷 UID 是 791222
 * 我也考了上午的J组，具体迷惑行为请看上午的~
 * 我写了个checker.py，给大家公开，供大家快速测大样例
 */

/* checker.py
import os

name = input('Input the problem name: ')
sample_dir = f'../down/{name}'
sample_cnt = len(os.listdir(sample_dir)) // 2
os.system(f'g++ ./{name}.cpp -o ./{name} -O2 -std=c++14 -static')
for num in range(1, sample_cnt + 1):
    input_file = f'../down/{name}/{name}{num}.in'
    output_file = f'./{name}.out'
    answer_file = f'../down/{name}/{name}{num}.ans'
    os.system(f'cp {input_file} ./{name}.in')
    os.system(f'./{name}')
    output_file_steam = open(output_file, 'r', encoding='utf-8')
    answer_file_steam = open(answer_file, 'r', encoding='utf-8')
    if output_file_steam.read() == answer_file_steam.read():
        print('Correct completely!')
    else:
        print(f'Wrong Answer on test #{num}')
    output_file_steam.close()
    answer_file_steam.close()
*/