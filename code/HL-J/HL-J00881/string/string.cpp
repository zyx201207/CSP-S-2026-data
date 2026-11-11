#include <bits/stdc++.h>
using namespace std;

const int SIDE = 2e5 + 5;
pair<int, char> s[SIDE];
int n;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);


    cin >> n;
    int pos = 1, cnt;
    char c, last = ' ';
    for (int i = 1; i <= n; i++) {
        cin >> cnt >> c;
        s[pos].first = cnt, s[pos].second = c;
        pos++;
    }

    int i = 1, j = n;
    long long ans = 0;
    while (i < j) {
        if (s[i].first == 0) {
            i++;
            continue;
        } else if (s[j].first == 0) {
            j--;
            continue;
        }

        int temp = min(s[i].first, s[j].first);
        if (s[i].second == s[j].second) {
            s[i].first -= temp;
            s[j].first -= temp;
        } else {
            s[i].first -= temp;
            s[j].first -= temp;
            ans += temp;
        }
    }

    cout << ans;


    fclose(stdin);
    fclose(stdout);
}
