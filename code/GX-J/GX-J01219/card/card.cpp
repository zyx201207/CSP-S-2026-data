#include <iostream>
#include <vector>
using namespace std;
int finder(vector<int> vec, int to_find) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == to_find) return i;
    }
    return -1;
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int cnt[m] = {0};
    for (int i = 0; i < n; i++) {
        vector<int> table;
        for (int j = i; j < n; j++) {
            int a;
            cin >> a;
            const int x = finder(table, a);
            if (x == -1) table.push_back(a);
            else for (int k = 1; k < x; k++) table.pop_back();
                for (int j = 0; j < m; j++) {
                const int x2 = finder(table, j + 1);
                if (x2 != -1) cnt[x2]++;
            }
        }
    }
    for (int i = 0; i < m; i++) cout << cnt[i] << ' ';
    return 0;
}
