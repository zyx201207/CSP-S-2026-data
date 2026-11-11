#include<bits/stdc++.h>

std::vector<int> a;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> anss(m + 1, 0);
    for (int i = 1;i <= n;i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    for (int i = 1;i <= n;i++) {
        std::vector<int> b;
        std::vector<int> table;
        for (int j = i - 1;j < n;j++) {
            b.push_back(a[j]);
        }
        for (int j = 0;j < b.size();j++) {
            bool flag = true;
            for (int k = 0;k < table.size();k++) {
                if (b[j] == table[k]) {
                    for (int t = k + 1;t < table.size();t++) {
                        table.erase(table.begin() + t);
                    }
                    flag = false;
                    break;
                }
            }
            if (flag) table.push_back(b[j]);
        }
        for (int j = 0;j < table.size();j++) {
            for (int k = 1;k <= m;k++) {
                if (table[j] == k) {
                    anss[k]++;
                }
            }
        }
    }
    for (int i = 1;i <= m;i++) {
        std::cout << anss[i] << " ";
    }
    return 0;
}
